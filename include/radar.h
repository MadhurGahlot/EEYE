#ifndef FC36AB42_6740_4C66_A2C9_8031397C262D
#define FC36AB42_6740_4C66_A2C9_8031397C262D
#include<vector>
using namespace std;
#include "raylib.h"

class Radar{
    public:
   void Update();
   void Draw();
   Radar();


private: 
Vector2 centre ;
float radius;
float sweepangle;
float sweepspeed;
float range;
bool isScanning;



};









#endif /* FC36AB42_6740_4C66_A2C9_8031397C262D */
