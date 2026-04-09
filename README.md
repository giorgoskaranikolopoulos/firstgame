# Square Game

A small 2D demo built in C and C++ using raylib. Two rectangles bounce around a window with movement speed that is fully independent of the frame rate.

## Features

* Frame-rate independent movement using delta time
* Two implementations: procedural C (code.c) and object-oriented C++ (code.cpp)
* Built with raylib 4.5

## Requirements

* GCC or G++ compiler
* raylib installed on your system

## Build & Run

**C version:**

    gcc code.c -lraylib -lm -lpthread -ldl -o squaregame
    ./squaregame

**C++ version:**

    g++ code.cpp -lraylib -lm -lpthread -ldl -o squaregame
    ./squaregame

## What I Learned

* How to set up a game loop with raylib
* How to decouple movement speed from FPS using elapsed time (delta time)
* Structuring game logic with classes in C++ vs. procedural style in C
