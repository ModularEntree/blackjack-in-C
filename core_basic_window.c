/*******************************************************************************************
*
*   raylib [core] example - Basic window (adapted for HTML5 platform)
*
*   This example is prepared to compile for PLATFORM_WEB, PLATFORM_DESKTOP and PLATFORM_RPI
*   As you will notice, code structure is slightly diferent to the other examples...
*   To compile it for PLATFORM_WEB just uncomment #define PLATFORM_WEB at beginning
*
*   This example has been created using raylib 1.3 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2015 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>



//----------------------------------------------------------------------------------
// Global Variables Definition
//----------------------------------------------------------------------------------
int screenWidth = 1280;
int screenHeight = 720;

typedef struct Cards {
    Texture2D cA;
    Texture2D c2;
    Texture2D c3;
    Texture2D c4;
    Texture2D c5;
    Texture2D c6;
    Texture2D c7;
    Texture2D c8;
    Texture2D c9;
    Texture2D c10;
    Texture2D cK;
    Texture2D backfaceB;
    Texture2D backfaceR;
}Cards;

const char *cards[13] = {"ace_H", "Two_H", "Three_H", "Four_H", "Five_H", "Six_H", "Seven_H", "Eight_H", "Nine_H", "Ten_H", "Jack_H", "Queen_H", "King_H"};

//----------------------------------------------------------------------------------
// Module Functions Declaration
//----------------------------------------------------------------------------------
void UpdateDrawFrame(Cards checkerboard);     // Update and Draw one frame

//----------------------------------------------------------------------------------
// Main Enry Point
//----------------------------------------------------------------------------------
int main()
{
    // Initialization
    srand(time(NULL));

    InitWindow(screenWidth, screenHeight, "Blackjack");

    Cards deck;
    deck.cA = LoadTexture("../img/ace_H.png");
    deck.c2 = LoadTexture("../img/Two_H.png");
    deck.c3 = LoadTexture("../img/Three_H.png");
    deck.c4 = LoadTexture("../img/Four_H.png");
    deck.c5 = LoadTexture("../img/Five_H.png");
    deck.c6 = LoadTexture("../img/Six_H.png");
    deck.c7 = LoadTexture("../img/Seven_H.png");
    deck.c8 = LoadTexture("../img/Eight_H.png");
    deck.c9 = LoadTexture("../img/Nine_H.png");
    deck.c10 = LoadTexture("../img/Ten_H.png");
    deck.backfaceB = LoadTexture("../img/backfaceB.png");
    deck.backfaceR = LoadTexture("../img/backfaceR.png");
    deck.cK = LoadTexture("../img/King_H.png");

    //--------------------------------------------------------------------------------------
    //LoadFontFromImage((image){"resources/alagard.png"});

    Image Icon = LoadImage("../img/Blackjack-icon.png");

    SetWindowIcon(Icon);



    SetTargetFPS(60);   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        UpdateDrawFrame(deck);
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(deck.cA);
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------


    return 0;
}

//----------------------------------------------------------------------------------
// Module Functions Definition
//----------------------------------------------------------------------------------
void UpdateDrawFrame(Cards Tcheckerboard)
{
    // Update
    //----------------------------------------------------------------------------------
    // TODO: Update your variables here
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

        ClearBackground(DARKERGREEN);

/*
    DrawCircle(screenWidth/4, screenHeight/2, 50, DARKBROWN);
DrawText("O", screenWidth/4-15, screenHeight/2-20, 45, BEIGE);
    DrawCircle(3*screenWidth/4, screenHeight/2, 50, DARKBROWN);
    DrawText("O", 3*screenWidth/4-15, screenHeight/2-20, 45, BEIGE);
    DrawCircle(2*screenWidth/4, screenHeight/2, 50, DARKBROWN);

    DrawRectangleRounded((Rectangle){screenWidth/2-100, screenHeight/2-25, 200, 50}, 0.5, 10, DARKBROWN);

    DrawText("W", 2*screenWidth/4-15, screenHeight/2-20, 45, BEIGE);
*/
    DrawTextureEx(Tcheckerboard.cA,(Vector2) {3.5*screenWidth/9, 50},0 ,0.69 , WHITE);
    DrawTextureEx(Tcheckerboard.backfaceR,(Vector2) {4.5*screenWidth/9, 50},0 ,0.69 , WHITE);
    //DrawTextureRec(Tcheckerboard.backface, (Rectangle){0, 0, 100, 100}, (Vector2){screenWidth/2-50, screenHeight/2-50}, WHITE);
    DrawTextureEx(Tcheckerboard.backfaceB,(Vector2) {4*screenWidth/16, 450},0 ,1 , WHITE);
    DrawTextureEx(Tcheckerboard.c9,(Vector2) {7*screenWidth/16, 450},0 ,1 , WHITE);
    DrawTextureEx(Tcheckerboard.cK,(Vector2) {10*screenWidth/16, 450},0 ,1 , WHITE);




        EndDrawing();
    //----------------------------------------------------------------------------------
}