#include "raylib.h"
#include <time.h>
#include <stdio.h>   

#define screenWidth 800
#define screenHeight 450

// Syntax for creating a class
class MyRectangle { // Ολες οι κλάσεις κατα σύμβαση ξεκινάνε με κεφαλαίο γράμμα. Αντί για rectangle θα έλεγα MyRectangle.
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
    int x,y; 
    Color color;
    int width,height;
    int speedx,speedy;


    // Member functions (methods)
    MyRectangle(int x,int y,Color color,int height,int width,int speedx,int speedy) {
        this->x=x;
        this->y=y;
        this->color=color;
        this->height=height; 
        this->width=width;
        this->speedx=speedx;
        this->speedy=speedy;  
    }
    Color changeColor (int i) {
        // Function implementation
        int rectanglecolor; // ΤΟ Μετρό της Θεσσαλονικης?
        Color colors[3]; // καλύτερο όνομα: colors. matrix είναι πολύ γενικό.

        colors[0]=GREEN;
        colors[1]=BLUE;
        colors[2]=RED;

        rectanglecolor=i%3;

        return colors[rectanglecolor];
    }

    // τι είναι το price? τι είναι το sizeR και το sizeP? βάλε καλύτερα ονόματα.
    bool hitWallOR() {
        // από ότι βλέπω μπορείς δεν χρειάζεσαι μόνο το step σαν παράμετρο.
        if((this->x+this->width>=screenWidth)||(this->x<=0)) { // γιατί σε ενδιαφέρει το πρόσημο του step?
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
    int stepX,step2X,stepY,step2Y,i1,i2;
    Color matrix[3];
    MyRectangle rectangle1( 0,0,RED,50,50,80,80);
    MyRectangle rectangle2( 0,400,GREEN,50,50,80,80);
    clock_t start_time,end_time; 
    double elapsed_time,speedX,speedY,speed2X,speed2Y,loop_speedX,loop_speed2X,loop_speedY,loop_speed2Y;
    InitWindow(screenWidth,screenHeight, "raylib [core] example - basic window");


    // CONSTUCTOR για να μην έχεις αυτό το μακρινάρι που έχεις παρακάτω.

    stepX=0;
    stepY=0;
    step2X=0;
    step2Y=0;
    loop_speedX=0;
    loop_speedY=0;
    loop_speed2X=0;
    loop_speed2Y=0;
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
        
        if(rectangle1.hitWallOR()&&stepX!=0) {
            i1++;
            rectangle1.speedx=-rectangle1.speedx; // Κάνε μια συνάρτηση moveRectangle.
        }
        if(rectangle1.hitWallOR()&&stepY!=0) {
            i1++;
            rectangle1.speedy=-rectangle1.speedy;
        }
        if(rectangle2.hitWallOR()&&step2X!=0) {  
            rectangle2.speedx=-rectangle2.speedx;
            i2++;
        }
        if(rectangle2.hitWallOR()&&step2Y!=0) { 
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
