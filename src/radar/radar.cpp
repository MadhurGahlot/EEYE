#include<cmath>
#include "radar.h"
#include "raylib.h"
#include<string>
using namespace std;
Radar:: Radar() 
{  //radar constructor outside the class
    radarPanel = {180, 150, 400, 550};
    centre = {
        radarPanel.x + radarPanel.width / 2,
        radarPanel.y + radarPanel.height / 2
    };
    radius = 180;
    sweepAngle = 0.0f;
    sweepSpeed = 60.0f;
    range = 50.0f;
    isScanning = true;
    status = "ACTIVE";
    targets = 0;
 
}



void Radar::Update() //method outside of  class
{
    if (isScanning)
    {
        sweepAngle += sweepSpeed * GetFrameTime();

        if (sweepAngle >= 360.0f)
        {
            sweepAngle -= 360.0f;
        }
    }
}

void Radar::Draw() //method outside the class
{
   // DrawCircleLines(400, 400, 50, RED);
    // draw circles and sweep line
    int centerX = centre.x;
    int centerY = centre.y;
    
    int radius = min((int)radarPanel.width,
                     (int)radarPanel.height) / 2 - 20;

    Vector2 center = {(float)centerX, (float)centerY};

   DrawCircleLines(centerX, centerY, radius, GREEN);
  // for (int r = 20; r < radius; r += 20)
    //    DrawCircleLinesV(center, r, GREEN);
   // float angle = sweepAngle * DEG2RAD;
  // Vector2 endPoint;
 //endPoint.x = centre.x + cos(angle) * radius;
 ///endPoint.y = centre.y + sin(angle) * radius;
//DrawLineV(centre, endPoint, GREEN);
DrawCircleV(center, radius, WHITE);

for (int i = 0; i < 30; i++) {
    float trailAngle = (sweepAngle - i * 2.5f) * DEG2RAD;
    unsigned char alpha = (unsigned char)(200 - i * 6);
    Color trailColor = { 0, 255, 70, alpha };
    Vector2 ep = {
        centre.x + cosf(trailAngle) * radius,
        centre.y + sinf(trailAngle) * radius
    };
    DrawLineV(centre, ep, GREEN);
  // DrawLineV(centre, ep, trailColor);
}  
for (int r = 20; r < radius; r += 20){
    DrawCircleLinesV(center, r, GREEN);
    int kmvalue= (int)((r / (float)radius) * range);
    char label[10];
    sprintf(label, "%dkm", kmvalue);
    DrawText(label, centerX + r + 2, centerY - 12, 10, PINK);


}
  DrawLine(centerX - radius,
             centerY,
             centerX + radius,
             centerY,
             ORANGE);

    DrawLine(centerX,
             centerY - radius,
             centerX,
             centerY + radius,
             ORANGE);

    DrawCircleV(center, 5, GREEN);

    }


