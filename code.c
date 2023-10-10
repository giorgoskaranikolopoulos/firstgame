#include "raylib.h"
#include <time.h>
#include <stdio.h>   
int main(void)
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;
    int x1,y1,x2,y2,stepX,step2X,stepY,step2Y,metro,i;
    Color matrix[3];
    clock_t start_time,end_time;  // Η αφήνεις κενά μετά το κόμμα ή όχι
    double elapsed_time,speedX,speedY,speed2X,speed2Y,loop_speedX,loop_speed2X,loop_speedY,loop_speed2Y;
    InitWindow(screenWidth,screenHeight, "raylib [core] example - basic window");

     x1=0; 
     y1=0;
     x2=0; 
     y2=400;
     stepX=0;
     stepY=0;
     step2X=0;
     step2Y=0;
     speedX=80;
     speedY=80;
     speed2X=80;
     speed2Y=80;
     loop_speedX=0;
     loop_speedY=0;
     loop_speed2X=0;
     loop_speed2Y=0;
     i=3;
     metro=0;
     matrix[0]=GREEN;
     matrix[1]=BLUE;
     matrix[2]=RED;
     
    SetTargetFPS(120); // Set our game to run at 60 frames-per-second

    // Επίσης χρησιμοποίησε tabs αντί για spaces για να είσαι consistent παντού. Τα x=0, y=0 κτλ είναι ένα κενό παραπάνω μέσα από ότι το SetTargetFPS()
    
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {   // Start the timer
        start_time = clock();

        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawText("Congrats! You created your first window!",190,225,20,LIGHTGRAY);
            DrawRectangle(x1,y1,50,50,GREEN); // Draw a color-filled rectangl
            DrawRectangle(x2,y2,50,50,matrix[metro]); // Draw a color-filled rectangl
        EndDrawing();

        x1=x1+stepX;
        y1=y1+stepY;
        
        x2=x2+step2X;
        y2=y2+step2Y;
        
        if((x1+50>=screenWidth&&stepX>0)||(x1<=0&&stepX<0)) {
            speedX=-speedX;
        }
        if((y1+50>=screenHeight&&stepY>0)||(y1<=0&&stepY<0)) {
            speedY=-speedY;
        }
        if((x2+50>=screenWidth&&step2X>0)||(x2<=0&&step2X<0)) {  
            speed2X=-speed2X;
            metro=i%3;
            i++;
        }
        if((y2+50>=screenHeight&&step2Y>0)||(y2<=0&&step2Y<0)) { 
            speed2Y=-speed2Y;
            metro=i%3;
            i++;
        }
        
        // Πάρα πολλές συνθήκες. Μπορεί να γίνει με δύο συνθήκες αν έχεις διαφορετική ταχύτητα για x και y.
        // Stop the timer
        end_time = clock();  // Και εδώ είναι λάθος τα κενά. Bάλε tabs.
      
        // Calculate the elapsed time in seconds
        elapsed_time = (double)(end_time-start_time)/(double)CLOCKS_PER_SEC;  // ή θα αφήνεις κενό ανάμεσα στα αριθμητικά συμβολα ή όχι.

        // Μπορούμε να αποφύγουμε όλες τις συνθήκες. Σκέψου το.

        loop_speedX=loop_speedX+elapsed_time*speedX;
        stepX=loop_speedX;
        loop_speedX=loop_speedX-stepX;
        
        loop_speedY=loop_speedY+elapsed_time*speedY;
        stepY=loop_speedY;
        loop_speedY=loop_speedY-stepY;
        
        printf("%d %f \n",stepX,elapsed_time); // Η αφήνεις κενά μετά το κόμμα ή όχι
        
        // second rectangle 
        loop_speed2X=loop_speed2X+elapsed_time*speed2X;
        step2X=loop_speed2X;
        loop_speed2X=loop_speed2X-step2X;
        
        loop_speed2Y=loop_speed2Y+elapsed_time*speed2Y;
        step2Y=loop_speed2Y;
        loop_speed2Y=loop_speed2Y-step2Y;
     }
     
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
