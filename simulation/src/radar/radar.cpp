#include "radar.h"
#include "raylib.h"
#include <cmath>
#include <string>

using namespace std;
Radar::Radar() { // radar constructor outside the class
  radarPanel = {180, 150, 400, 550};
  centre = {radarPanel.x + radarPanel.width / 2,
            radarPanel.y + radarPanel.height / 2};
  radius = 180;
  sweepAngle = 0.0f;
  sweepSpeed = 60.0f;
  range = 50.0f;
  isScanning = true;
  status = "ACTIVE";
  powerButton = {15, 210, 150, 50};
  scanningbutton = {15,270,150,50};
}

void Radar::Update()
{
    UpdatePowerButton();
    UpdateScanningButton();

    if (!radarEnabled)
    {
      status = "OFFLINE";
      isScanning = false;
      return;
    }
    if (isScanning)
    {
    status = "ACTIVE";
    sweepAngle += sweepSpeed * GetFrameTime();
    if (sweepAngle >= 360.0f)
    {
    sweepAngle -= 360.0f;
    }
    }
    else{
    status = "STANDBY";
    }
}

void Radar::Draw() // method outside the class
{

  int centerX = centre.x;
  int centerY = centre.y;

  int radius = min((int)radarPanel.width, (int)radarPanel.height) / 2 - 20;

  Vector2 center = {(float)centerX, (float)centerY};

  DrawCircleLines(centerX, centerY, radius, GREEN);
  // for (int r = 20; r < radius; r += 20)
  //    DrawCircleLinesV(center, r, GREEN);
  // float angle = sweepAngle * DEG2RAD;
  // Vector2 endPoint;
  // endPoint.x = centre.x + cos(angle) * radius;
  /// endPoint.y = centre.y + sin(angle) * radius;
  // DrawLineV(centre, endPoint, GREEN);

  DrawCircleV(center, radius, WHITE);

  // if (radarEnabled) {
  if (radarEnabled) {
    if(isScanning){
    for (int i = 0; i < 30; i++) {
      float trailAngle = (sweepAngle - i * 2.5f) * DEG2RAD;
      unsigned char alpha = (unsigned char)(200 - i * 6);
      Color trailColor = {0, 255, 70, alpha};
      Vector2 ep = {centre.x + cosf(trailAngle) * radius,
                    centre.y + sinf(trailAngle) * radius};
      // DrawLineV(centre, ep, GREEN);
      DrawLineV(centre, ep, trailColor);
    }
    }
    // }
    
    for (int r = 20; r < radius; r += 20) {
      DrawCircleLinesV(center, r, GREEN);
      int kmvalue = (int)((r / (float)radius) * range);
      char label[10];
      // sprintf(label, "%dkm", kmvalue);
      sprintf(label, "%d", kmvalue);
      DrawText(label, centerX + r + 2, centerY - 12, 10, PINK);
    }
    DrawLine(centerX - radius, centerY, centerX + radius, centerY, ORANGE);

    DrawLine(centerX, centerY - radius, centerX, centerY + radius, ORANGE);

    DrawCircleV(center, 5, GREEN);
  }
  DrawScanningButton();
  DrawPowerButton();
}

void Radar::UpdatePowerButton() {
  Vector2 mouse = GetMousePosition();

    if (CheckCollisionPointRec(mouse, powerButton) &&
    IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
      radarEnabled = !radarEnabled;
      if (!radarEnabled)
      {
      isScanning = false;
     }
    }
    if (IsKeyPressed(KEY_R))
    {
        radarEnabled = !radarEnabled;
        if (!radarEnabled)
        {
        isScanning = false;
        }
    }
}

void Radar::DrawPowerButton() {
  DrawRectangleRec(powerButton, radarEnabled ? DARKGREEN : DARKGRAY);

  DrawRectangleLinesEx(powerButton, 2, WHITE);

  DrawText(radarEnabled ? "RADAR ON" : "RADAR OFF", powerButton.x + 20,
           powerButton.y + 15, 20, WHITE);
}

void Radar::UpdateScanningButton() {
  Vector2 mouse = GetMousePosition();
if (!radarEnabled)
    {
    isScanning = false;
    return;
    }
    if (CheckCollisionPointRec(mouse, scanningbutton) &&
    IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
      isScanning = !isScanning;
    }
    if (IsKeyPressed(KEY_S))
    {
        isScanning = !isScanning;
    }
}

void Radar ::DrawScanningButton(){ 
  DrawRectangleRec(scanningbutton,isScanning ? DARKGREEN : DARKGRAY);
  DrawRectangleLinesEx(scanningbutton,2,WHITE);

  DrawText(isScanning ? "Scanning ON" : "Scanning OFF", scanningbutton.x + 20,
           scanningbutton.y + 15, 18, WHITE);

}