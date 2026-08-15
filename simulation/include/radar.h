#ifndef RADAR_H
#define RADAR_H

#include "raylib.h"
#include <string>
#include <vector>
using namespace std;

struct RadarInfo {
  string status;
  int targets;
  bool isScanning;
  float range;
};

// Class definition
class Radar {
private:
  Vector2 centre;
  float radius;
  float sweepAngle;
  float sweepSpeed;
  float range;
  bool isScanning;
  Rectangle radarPanel;
  string status;
  int targets;
  bool radarEnabled = true;
  Rectangle powerButton;
  Rectangle scanningbutton;
  void UpdatePowerButton();
  void DrawPowerButton();
  void UpdateScanningButton();
  void DrawScanningButton();
     
public:
  Radar();
  void Update();
  void Draw();

  // Inline getter returning the RadarInfo struct
  RadarInfo getInfo() const { return {status, targets, isScanning, range}; }
};

#endif // RADAR_H
