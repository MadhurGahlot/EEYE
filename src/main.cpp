//#include "raylib.h"
#include "raylib.h"
#include "radar.h"
#include <algorithm>
#include <ctime>
#include<string>

using namespace std;

const int screenWidth = 800;
const int screenHeight = 800;
const int topBarHeight = 150;
const int bottomBarHeight = 100;
const int leftPanelWidth = 180;
const int rightPanelWidth = 220;
const int fps =120;
Radar radar;

Rectangle topBar = {
    0,
    0,
    screenWidth,
    topBarHeight
};

Rectangle leftPanel = {
    0,
    topBarHeight,
    leftPanelWidth,
    screenHeight - topBarHeight - bottomBarHeight
};

Rectangle radarPanel = {
    leftPanelWidth,
    topBarHeight,
    screenWidth - leftPanelWidth - rightPanelWidth,
    screenHeight - topBarHeight - bottomBarHeight
};

Rectangle rightPanel = {
    screenWidth - rightPanelWidth,
    topBarHeight,
    rightPanelWidth,
    screenHeight - topBarHeight - bottomBarHeight
};

Rectangle bottomBar = {
    0,
    screenHeight - bottomBarHeight,
    screenWidth,
    bottomBarHeight
};
void UpdateGame()
{
    
}

void DrawTopBar()
{

time_t now = time(0);
tm *ltm = localtime(&now);
 string time ;
 time = ltm->tm_hour;
 char currentTime[20];

    sprintf(currentTime,
            "%02d:%02d:%02d",
            ltm->tm_hour,
            ltm->tm_min,
            ltm->tm_sec);

    
    DrawRectangleLinesEx(topBar, 1, RED);

    DrawText("AIR DEFENSE COMMAND CENTER",
             150,
             20,
             22,
             GREEN);

    DrawText(currentTime,
             screenWidth - 160,
             20,
             20,
             GREEN);
}

void DrawLeftPanel()
{
    DrawRectangleLinesEx(leftPanel, 1, RED);

    DrawText("CONTROL PANEL",
             15,
             topBarHeight + 20,
             18,
             BLUE);
}

void DrawCentrePanel()
{
    DrawRectangleLinesEx(radarPanel, 2, RED);
    radar.Draw();
    

}

void DrawRightPanel()
{
    DrawRectangleLinesEx(rightPanel, 2, RED);

    DrawText("TARGET INFO",
             rightPanel.x + 20,
             topBarHeight + 20,
             20,
             BLUE);
}

void DrawBottomBar()
{
    DrawRectangleLinesEx(bottomBar, 2, RED);
    RadarInfo info = radar.getInfo();
    DrawText(
        TextFormat(
            "STATUS: %s | FPS: %d | TARGETS: %d | RANGE: %.0f km",
            info.status.c_str(),
            GetFPS(),
            info.targets,
            info.range
        ),
        20,
        bottomBar.y + 25,
        20,
        GREEN
    );
}

void DrawDashboard()
{
    DrawTopBar();
    DrawLeftPanel();
    DrawCentrePanel();
    DrawRightPanel();
    DrawBottomBar();
}

void Draw()
{

    Color backgroundcolor = {30,40,80,};
    ClearBackground(backgroundcolor);

    DrawDashboard();
}


int main(){
    
    InitWindow(screenWidth, screenHeight, "SENTINAL COMMAND CENTER");
    SetTargetFPS(fps);

    while (!WindowShouldClose())
    {
        radar.Update();
        UpdateGame();
       // radar.Draw();
        BeginDrawing();
        Draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}