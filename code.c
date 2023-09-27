/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2023 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include <time.h>
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    int x,y,step;
    bool flagO,flagK;
    clock_t start_time, end_time;
    double elapsed_time,speed,loop_speed;
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
 
    SetTargetFPS(120);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
     x=0;
     y=0;
     step=0;
     speed=80;
     loop_speed=0;
    // Main game loop
    
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {   // Start the timer
        start_time = clock();
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("Congrats! You created your first window!", 190, 225, 20, LIGHTGRAY);
            DrawRectangle(x, y, 50, 50, GREEN); // Draw a color-filled rectangl
            
        EndDrawing();
        //----------------------------------------------------------------------------------
        if(x+50>=screenWidth)
        {flagO=true;}
        else if(x<=0){
            flagO=false;
        }
        if(y+50>=screenHeight)
        {flagK=true;}
        else if(y<=0){
            flagK=false;
        }
        if(flagO)
        {x=x-step;
        }
        else{
            x=x+step;
        }
        if(flagK)
        {y=y-step;
        }
        else{
            y=y+step;
        }   
       // Stop the timer
      end_time = clock();  
      
      // Calculate the elapsed time in seconds
      elapsed_time = (double)(end_time - start_time) / (double)CLOCKS_PER_SEC;   
      if(loop_speed>=1){
          step=loop_speed;
          loop_speed=loop_speed - step;
          
      }
      else if(elapsed_time*speed<1){
          
          loop_speed=loop_speed + elapsed_time*speed;
      }
      else {   
         step=elapsed_time*speed; 
      }
      printf("%d %f\n",step,elapsed_time);  
      
     }
     
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
