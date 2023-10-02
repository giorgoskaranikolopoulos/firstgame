#include "raylib.h"
#include <time.h>

int main(void)
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;
    int x,y,step; // Πρέπει να είσαι σταθερός στον τρόπο που τα γράφεις. 'Η αφήνεις κενά μετά το κόμμα ή όχι
    bool flagO,flagK; // 'Η αφήνεις κενά μετά το κόμμα ή όχι
    clock_t start_time,end_time;  // Η αφήνεις κενά μετά το κόμμα ή όχι
    double elapsed_time,speed,loop_speed; // Η αφήνεις κενά μετά το κόμμα ή όχι
    InitWindow(screenWidth,screenHeight, "raylib [core] example - basic window");

     x=0; 
     y=0;
     step=0;
     speed=80;
     loop_speed=0;
 
    SetTargetFPS(120); // Set our game to run at 60 frames-per-second

    // Aρχικοποίησε της μεταβλητές εκεί που τις δηλώνεις. 
    // Επίσης χρησιμοποίησε tabs αντί για spaces για να είσαι consistent παντού. Τα x=0, y=0 κτλ είναι ένα κενό παραπάνω μέσα από ότι το SetTargetFPS()
    
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {   // Start the timer
        start_time = clock();

        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawText("Congrats! You created your first window!",190,225,20,LIGHTGRAY);
            DrawRectangle(x,y,50,50,GREEN); // Draw a color-filled rectangl           
        EndDrawing();

        // Πρέπει να εισαι σταθερός στον τρόπο γραφής σου και στο πως βάζεις τις αγκύλες. Η θα χρησιμοποιείς
        // if(example condition) {
        //     bla bla 
        //     bla
        // }
        
        // ή
        
        // if(example condition) 
        // {
        //     bla bla 
        //     bla
        // }
        
        if(x+50>=screenWidth) {
            speedX=-abs(speedX);
        }
        else if(x<=0) {
            speedX=abs(speedX); 
        }
        if(y+50>=screenHeight) {
            speedY=-abs(speedY);
        }
        else if(y<=0) {
            speedY=abs(speedY);
        }
      
        // Πάρα πολλές συνθήκες. Μπορεί να γίνει με δύο συνθήκες αν έχεις διαφορετική ταχύτητα για x και y.
        // Stop the timer
        end_time = clock();  // Και εδώ είναι λάθος τα κενά. Bάλε tabs.
      
        // Calculate the elapsed time in seconds
        elapsed_time = (double)(end_time-start_time)/(double)CLOCKS_PER_SEC;  // ή θα αφήνεις κενό ανάμεσα στα αριθμητικά συμβολα ή όχι.

        // Μπορούμε να αποφύγουμε όλες τις συνθήκες. Σκέψου το.

        loop_speed=loop_speed+elapsed_time*speed;
        step=loop_speed;
        loop_speed=loop_speed-step;
        
        printf("%d %f\n",step,elapsed_time); // Η αφήνεις κενά μετά το κόμμα ή όχι
      
     }
     
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
