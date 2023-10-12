#include "raylib.h"
#include <time.h>
#include <stdio.h>   

#define screenWidth 800
#define screenHeight 450

// Syntax for creating a class
class rectangle { // Ολες οι κλάσεις κατα σύμβαση ξεκινάνε με κεφαλαίο γράμμα. Αντί για rectangle θα έλεγα Rectangle.
    // Access specifier
public:
    // Member variables (also known as data members)
    /*Σωστά γενικά, θα έλεγα να ομαδοποιεις παραμέτρους που έχουν σχέση μεταξύ τους.
    πχ. 
    int x,y;
    int width,height;
    int speedx,speedy;
    Color color;
    */
    int x;
    int y; 
    Color color;
    int width;
    int height;
    int speedx;
    int speedy;

    // Member functions (methods)

    Color changeColor (int i) {
        // Function implementation
        int metro; // ΤΟ Μετρό της Θεσσαλονικης?
        Color matrix[3]; // καλύτερο όνομα: colors. matrix είναι πολύ γενικό.

        matrix[0]=GREEN;
        matrix[1]=BLUE;
        matrix[2]=RED;

        metro=i%3;

        return matrix[metro];
    }

    // τι είναι το price? τι είναι το sizeR και το sizeP? βάλε καλύτερα ονόματα.
    bool hitWall(int price,int step,int sizeR,int sizeP) {
        // από ότι βλέπω μπορείς δεν χρειάζεσαι μόνο το step σαν παράμετρο.
        if((price+sizeR>=sizeP&&step>0)||(price<=0&&step<0)) { // γιατί σε ενδιαφέρει το πρόσημο του step?
            return true;
        }
        else {
            return false;
        }
        
    }
};

int main(void)
{
    // Initialization
    int stepX,step2X,stepY,step2Y,metro,i1,i2;
    Color matrix[3];
    rectangle rectangle1,rectangle2;
    clock_t start_time,end_time; 
    double elapsed_time,speedX,speedY,speed2X,speed2Y,loop_speedX,loop_speed2X,loop_speedY,loop_speed2Y;
    InitWindow(screenWidth,screenHeight, "raylib [core] example - basic window");


    // CONSTUCTOR για να μην έχεις αυτό το μακρινάρι που έχεις παρακάτω.
    rectangle1.x=0;
    rectangle1.y=0;    
    rectangle2.x=0;
    rectangle2.y=400;
    stepX=0;
    stepY=0;
    step2X=0;
    step2Y=0;
    rectangle1.speedx=80;
    rectangle1.speedy=80;
    rectangle2.speedx=80;
    rectangle2.speedy=80;
    loop_speedX=0;
    loop_speedY=0;
    loop_speed2X=0;
    loop_speed2Y=0;
    rectangle1.height=50;
    rectangle1.width=50;
    rectangle2.height=50;
    rectangle2.width=50;
    i1=3;
    i2=3;
     
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
            DrawRectangle(rectangle1.x,rectangle1.y,rectangle1.width,rectangle1.height,rectangle1.changeColor(i1)); // Draw a color-filled rectangl
            DrawRectangle(rectangle2.x,rectangle2.y,rectangle1.width,rectangle2.height,rectangle2.changeColor(i2)); // Draw a color-filled rectangl
        EndDrawing();

        rectangle1.x=rectangle1.x+stepX;
        rectangle1.y=rectangle1.y+stepY;
        
        rectangle2.x=rectangle2.x+step2X;
        rectangle2.y=rectangle2.y+step2Y;
        
        if(rectangle1.hitWall(rectangle1.x,stepX,rectangle1.width,screenWidth)) {
            i1++;
            rectangle1.speedx=-rectangle1.speedx; // Κάνε μια συνάρτηση moveRectangle.
        }
        if(rectangle1.hitWall(rectangle1.y,stepY,rectangle1.height,screenHeight)) {
            i1++;
            rectangle1.speedy=-rectangle1.speedy;
        }
        if(rectangle2.hitWall(rectangle2.x,step2X,rectangle2.width,screenWidth)) {  
            rectangle2.speedx=-rectangle2.speedx;
            i2++;
        }
        if(rectangle2.hitWall(rectangle2.y,step2Y,rectangle2.height,screenHeight)) { 
            rectangle2.speedy=-rectangle1.speedy;           
            i2++;
        }
        
        // Stop the timer
        end_time = clock();  
      
        // Calculate the elapsed time in seconds
        elapsed_time = (double)(end_time-start_time)/(double)CLOCKS_PER_SEC;  // ή θα αφήνεις κενό ανάμεσα στα αριθμητικά συμβολα ή όχι.


        loop_speedX=loop_speedX+elapsed_time*rectangle1.speedx;
        stepX=loop_speedX;
        loop_speedX=loop_speedX-stepX;
        
        loop_speedY=loop_speedY+elapsed_time*rectangle1.speedy;
        stepY=loop_speedY;
        loop_speedY=loop_speedY-stepY;
        
        printf("%d %f \n",stepX,elapsed_time); 
        
        // second rectangle 
        loop_speed2X=loop_speed2X+elapsed_time*rectangle2.speedx;
        step2X=loop_speed2X;
        loop_speed2X=loop_speed2X-step2X;
        
        loop_speed2Y=loop_speed2Y+elapsed_time*rectangle2.speedy;
        step2Y=loop_speed2Y;
        loop_speed2Y=loop_speed2Y-step2Y;
    }
     
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
