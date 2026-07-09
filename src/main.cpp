#include <raylib.h>
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
const int fps =60;


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

    int centerX = radarPanel.x + radarPanel.width / 2;
    int centerY = radarPanel.y + radarPanel.height / 2;

    int radius = min((int)radarPanel.width,
                     (int)radarPanel.height) / 2 - 20;

    Vector2 center = {(float)centerX, (float)centerY};

    DrawCircleLines(centerX, centerY, radius, GREEN);

    for (int r = 20; r < radius; r += 20)
        DrawCircleLinesV(center, r, GREEN);

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

    DrawText("STATUS: ACTIVE | FPS: 60 | TARGETS: 0 | RANGE: 50 km",
             20,
             bottomBar.y + 25,
             20,
             GREEN);
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
    ClearBackground(BLACK);

    DrawDashboard();
}


int main()
{
    InitWindow(screenWidth, screenHeight, "SENTINAL COMMAND CENTER");
    SetTargetFPS(fps);

    while (!WindowShouldClose())
    {
        UpdateGame();

        BeginDrawing();
        Draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}