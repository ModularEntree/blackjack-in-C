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
#include <unistd.h>



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
    Texture2D cQ;
    Texture2D cJ;

    Texture2D hA;
    Texture2D h2;
    Texture2D h3;
    Texture2D h4;
    Texture2D h5;
    Texture2D h6;
    Texture2D h7;
    Texture2D h8;
    Texture2D h9;
    Texture2D h10;
    Texture2D hK;
    Texture2D hJ;
    Texture2D hQ;

    Texture2D dA;
    Texture2D d2;
    Texture2D d3;
    Texture2D d4;
    Texture2D d5;
    Texture2D d6;
    Texture2D d7;
    Texture2D d8;
    Texture2D d9;
    Texture2D d10;
    Texture2D dK;
    Texture2D dJ;
    Texture2D dQ;

    Texture2D sA;
    Texture2D s2;
    Texture2D s3;
    Texture2D s4;
    Texture2D s5;
    Texture2D s6;
    Texture2D s7;
    Texture2D s8;
    Texture2D s9;
    Texture2D s10;
    Texture2D sK;
    Texture2D sJ;
    Texture2D sQ;

    Texture2D backfaceB;
    Texture2D backfaceR;
}Cards;

typedef struct pozice {
    Vector2 K1;
    Vector2 K2;
    Vector2 K3;
    Vector2 H1;
    Vector2 H2;
    Vector2 H3;
}pozice;

const char *cards[13] = {"ace_H", "Two_H", "Three_H", "Four_H", "Five_H", "Six_H", "Seven_H", "Eight_H", "Nine_H", "Ten_H", "Jack_H", "Queen_H", "King_H"};

//----------------------------------------------------------------------------------
// Module Functions Declaration
//----------------------------------------------------------------------------------
void UpdateDrawFrame(Cards checkerboard, pozice stul);     // Update and Draw one frame

//----------------------------------------------------------------------------------
// Main Enry Point
//----------------------------------------------------------------------------------
int main()
{
    // Initialization
    srand(time(NULL));

    InitWindow(screenWidth, screenHeight, "Blackjack");

    Cards deck;
    deck.hA = LoadTexture("../img/hearts/Ace.png");
    deck.h2 = LoadTexture("../img/hearts/Two.png");
    deck.h3 = LoadTexture("../img/hearts/Three.png");
    deck.h4 = LoadTexture("../img/hearts/Four.png");
    deck.h5 = LoadTexture("../img/hearts/Five.png");
    deck.h6 = LoadTexture("../img/hearts/Six.png");
    deck.h7 = LoadTexture("../img/hearts/Seven.png");
    deck.h8 = LoadTexture("../img/hearts/Eight.png");
    deck.h9 = LoadTexture("../img/hearts/Nine.png");
    deck.h10 = LoadTexture("../img/hearts/Ten.png");
    deck.hJ = LoadTexture("../img/hearts/Jack.png");
    deck.hQ = LoadTexture("../img/hearts/Queen.png");
    deck.hK = LoadTexture("../img/hearts/King.png");

    deck.cA = LoadTexture("../img/clubs/Ace.png");
    deck.c2 = LoadTexture("../img/clubs/Two.png");
    deck.c3 = LoadTexture("../img/clubs/Three.png");
    deck.c4 = LoadTexture("../img/clubs/Four.png");
    deck.c5 = LoadTexture("../img/clubs/Five.png");
    deck.c6 = LoadTexture("../img/clubs/Six.png");
    deck.c7 = LoadTexture("../img/clubs/Seven.png");
    deck.c8 = LoadTexture("../img/clubs/Eight.png");
    deck.c9 = LoadTexture("../img/clubs/Nine.png");
    deck.c10 = LoadTexture("../img/clubs/Ten.png");
    deck.cJ = LoadTexture("../img/clubs/Jack.png");
    deck.cQ = LoadTexture("../img/clubs/Queen.png");
    deck.cK = LoadTexture("../img/clubs/King.png");

    deck.dA = LoadTexture("../img/diamonds/Ace.png");
    deck.d2 = LoadTexture("../img/diamonds/Two.png");
    deck.d3 = LoadTexture("../img/diamonds/Three.png");
    deck.d4 = LoadTexture("../img/diamonds/Four.png");
    deck.d5 = LoadTexture("../img/diamonds/Five.png");
    deck.d6 = LoadTexture("../img/diamonds/Six.png");
    deck.d7 = LoadTexture("../img/diamonds/Seven.png");
    deck.d8 = LoadTexture("../img/diamonds/Eight.png");
    deck.d9 = LoadTexture("../img/diamonds/Nine.png");
    deck.d10 = LoadTexture("../img/diamonds/Ten.png");
    deck.dJ = LoadTexture("../img/diamonds/Jack.png");
    deck.dQ = LoadTexture("../img/diamonds/Queen.png");
    deck.dK = LoadTexture("../img/diamonds/King.png");

    deck.sA = LoadTexture("../img/spades/Ace.png");
    deck.s2 = LoadTexture("../img/spades/Two.png");
    deck.s3 = LoadTexture("../img/spades/Three.png");
    deck.s4 = LoadTexture("../img/spades/Four.png");
    deck.s5 = LoadTexture("../img/spades/Five.png");
    deck.s6 = LoadTexture("../img/spades/Six.png");
    deck.s7 = LoadTexture("../img/spades/Seven.png");
    deck.s8 = LoadTexture("../img/spades/Eight.png");
    deck.s9 = LoadTexture("../img/spades/Nine.png");
    deck.s10 = LoadTexture("../img/spades/Ten.png");
    deck.sJ = LoadTexture("../img/spades/Jack.png");
    deck.sQ = LoadTexture("../img/spades/Queen.png");
    deck.sK = LoadTexture("../img/spades/King.png");

    deck.backfaceB = LoadTexture("../img/backfaceB.png");
    deck.backfaceR = LoadTexture("../img/backfaceR.png");

    pozice stul;

    stul.K1 = (Vector2) {3.5*screenWidth/9, 50};
    stul.K2 = (Vector2) {4.5*screenWidth/9, 50};
    stul.K3 = (Vector2) {4.5*screenWidth/9, 50};
    stul.H1 = (Vector2) {4*screenWidth/16, 450};
    stul.H2 = (Vector2) {7*screenWidth/16, 450};
    stul.H3 = (Vector2) {10*screenWidth/16, 450};

    //--------------------------------------------------------------------------------------

    Image Icon = LoadImage("../img/Blackjack-icon.png");

    SetWindowIcon(Icon);



    SetTargetFPS(60);   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    system("echo amogus říká: \"Ahoj\"");

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        /*if(IsKeyPressed(KEY_SPACE)){
            UpdateTexture(deck.backfaceB, LoadImageColors(LoadImageFromTexture(deck.cA)));
            UpdateTexture(deck.backfaceR, LoadImageColors(LoadImage("../img/backfaceB.png")));
        }*/

        UpdateDrawFrame(deck, stul);
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    //UnloadTexture(deck.cA);
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------


    return 0;
}

//----------------------------------------------------------------------------------
// Module Functions Definition
//----------------------------------------------------------------------------------
void UpdateDrawFrame(Cards Tcheckerboard, pozice stul)
{

    // Update
    //----------------------------------------------------------------------------------
    // TODO: Update your variables here
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

    ClearBackground(DARKERGREEN);

    DrawText("Blackjack", 2*screenWidth/5, 2*screenHeight/5, 50, GOLD);
/*
    DrawCircle(screenWidth/4, screenHeight/2, 50, DARKBROWN);
DrawText("O", screenWidth/4-15, screenHeight/2-20, 45, BEIGE);
    DrawCircle(3*screenWidth/4, screenHeight/2, 50, DARKBROWN);
    DrawText("O", 3*screenWidth/4-15, screenHeight/2-20, 45, BEIGE);
    DrawCircle(2*screenWidth/4, screenHeight/2, 50, DARKBROWN);

    DrawRectangleRounded((Rectangle){screenWidth/2-100, screenHeight/2-25, 200, 50}, 0.5, 10, DARKBROWN);

    DrawText("W", 2*screenWidth/4-15, screenHeight/2-20, 45, BEIGE);
*/



    DrawTextureEx(Tcheckerboard.cA, stul.K1, 0, 0.69, WHITE);
    DrawTextureEx(Tcheckerboard.backfaceR, stul.K2, 0,0.69 , WHITE);

    DrawTextureEx(Tcheckerboard.backfaceB, stul.H1, 0 ,1 , WHITE);
    DrawTextureEx(Tcheckerboard.c9,stul.H2,0 ,1 , WHITE);
    DrawTextureEx(Tcheckerboard.cK,stul.H3,0 ,1 , WHITE);





        EndDrawing();
    //----------------------------------------------------------------------------------
}