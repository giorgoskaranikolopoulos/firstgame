#include "raylib.h"
#include <ctime>
#include <iostream>  

using namespace std;

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
    double speedx,speedy;
    double loop_speedX,loop_speedY;
    int stepX,stepY;

    // Member functions (methods)
    MyRectangle(int x,int y,Color color,int height,int width,double speedx,double speedy) {
        this->x=x;
        this->y=y;
        this->color=color;
        this->height=height; 
        this->width=width;
        this->speedx=speedx;
        this->speedy=speedy;
        this->loop_speedX=0;
        this->loop_speedY=0;
        this->stepX=0;
        this->stepY=0;  
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
    bool hitWallhorizontally() {
        // από ότι βλέπω μπορείς δεν χρειάζεσαι μόνο το step σαν παράμετρο.
        if((this->x+this->width>=screenWidth)||(this->x<=0)) { // γιατί σε ενδιαφέρει το πρόσημο του step?
            return true;
            cout << "flag=true" << endl;
        }
        else {
            return false;
            cout << "flag=false" << endl;
        }
        
    }

    bool hitWallvertically() {

        if((this->y+this->height>=screenHeight)||(this->y<=0)) { // γιατί σε ενδιαφέρει το πρόσημο του step?
            return true;
        }
        else {
            return false;
        }
        
    }
    void moveRectangleX(double elapsed_time) {
        this->x=this->x+this->stepX;  
        this->loop_speedX=this->loop_speedX+elapsed_time*this->speedx;
        this->stepX=this->loop_speedX;
        this->loop_speedX=this->loop_speedX-this->stepX;
        cout << "rectangle.stepX= " << this->stepX << endl;     
    }

    void moveRectangleY(double elapsed_time) {
        this->y=this->y+this->stepY;
        this->loop_speedY=this->loop_speedY+elapsed_time*this->speedy;
        this->stepY=this->loop_speedY;
        this->loop_speedY=this->loop_speedY-this->stepY;
        cout << "rectangle.stepY= " << this->stepY << endl;
        cout << "rectangle.x= " << this->x << endl; 
    }
};

int main(void)
{
    // Initialization
    int i1,i2;
    MyRectangle rectangle1( 0,0,RED,50,50,80,80);
    MyRectangle rectangle2( 0,400,GREEN,50,50,80,80);
    clock_t start_time,end_time; 
    double elapsed_time;
    InitWindow(screenWidth,screenHeight, "raylib [core] example - basic window");


    // CONSTUCTOR για να μην έχεις αυτό το μακρινάρι που έχεις παρακάτω.

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

        if(rectangle1.hitWallhorizontally()&&rectangle1.stepX!=0) {
            i1++;
            rectangle1.speedx=-rectangle1.speedx; // Κάνε μια συνάρτηση moveRectangle.
        }
        if(rectangle1.hitWallvertically()&&rectangle1.stepY!=0) {
            i1++;
            rectangle1.speedy=-rectangle1.speedy;
        }
        if(rectangle2.hitWallhorizontally()&&rectangle2.stepX!=0) {  
            rectangle2.speedx=-rectangle2.speedx;
            i2++;
        }
        if(rectangle2.hitWallvertically()&&rectangle2.stepY!=0) { 
            rectangle2.speedy=-rectangle1.speedy;           
            i2++;
        }
        
        // Stop the timer
        end_time = clock();  
      
        // Calculate the elapsed time in seconds
        elapsed_time = static_cast<double>(end_time-start_time)/(double)CLOCKS_PER_SEC;  // ή θα αφήνεις κενό ανάμεσα στα αριθμητικά συμβολα ή όχι.

        rectangle1.moveRectangleX(elapsed_time);
        rectangle1.moveRectangleY(elapsed_time);

        // second rectangle 
        rectangle2.moveRectangleX(elapsed_time);
        rectangle2.moveRectangleY(elapsed_time);      
    }      

    rectangle1.moveRectangleX(elapsed_time);
    rectangle1.moveRectangleY(elapsed_time);

    // second rectangle 
    rectangle2.moveRectangleX(elapsed_time);
    rectangle2.moveRectangleY(elapsed_time);  
     
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
