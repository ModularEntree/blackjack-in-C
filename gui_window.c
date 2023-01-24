#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include "gui_window.h"
#include "main.h"


extern int HandSumMe, HandSumHouse;
extern int HandMe[MAX_SIZE], HandHouse[MAX_SIZE];
extern int cardNumMe, cardNumHouse;
extern card ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king;
extern localization czech, english, def;

//----------------------------------------------------------------------------------
// Global Variables Definition
//----------------------------------------------------------------------------------
int screenWidth = 1280;
int screenHeight = 720;

bool bGame = true; // Should be false, but for testing purposes it is true
bool bHit = false;
bool bStand = false;
bool bPlayerTurn = true;

typedef struct pozice {
    Vector2 K1;
    Vector2 K2;
    Vector2 K3;
    Vector2 H1;
    Vector2 H2;
    Vector2 H3;
}pozice;

//const char *cards[13] = {"ace_H", "Two_H", "Three_H", "Four_H", "Five_H", "Six_H", "Seven_H", "Eight_H", "Nine_H", "Ten_H", "Jack_H", "Queen_H", "King_H"};

//----------------------------------------------------------------------------------
// Module Functions Declaration
//----------------------------------------------------------------------------------
void UpdateDrawFrame(Cards deck, Rectangle hit, Rectangle stand, Rectangle start, Texture2D aDeck[TEXTURE_COUNT]);     // Update and Draw one frame

//----------------------------------------------------------------------------------
// Main Enry Point
//----------------------------------------------------------------------------------
int main() {
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

    deck.backfaceB = LoadTexture("../img/backs/kittyback-blue.png");
    deck.backfaceR = LoadTexture("../img/backs/kittyback-red.png");

    pozice stul;

    stul.K1 = (Vector2) {3.5 * screenWidth / 9, 50};
    stul.K2 = (Vector2) {4.5 * screenWidth / 9, 50};
    stul.K3 = (Vector2) {4.5 * screenWidth / 9, 50};
    stul.H1 = (Vector2) {4 * screenWidth / 16, 450};
    stul.H2 = (Vector2) {7 * screenWidth / 16, 450};
    stul.H3 = (Vector2) {10 * screenWidth / 16, 450};

    ace.num = 1;
    ace.id = 'A';
    two.num = 2;
    two.id = '2';
    three.num = 3;
    three.id = '3';
    four.num = 4;
    four.id = '4';
    five.num = 5;
    five.id = '5';
    six.num = 6;
    six.id = '6';
    seven.num = 7;
    seven.id = '7';
    eight.num = 8;
    eight.id = '8';
    nine.num = 9;
    nine.id = '9';
    ten.num = 10;
    ten.id = 'X';
    jack.num = 10;
    jack.id = 'J';
    queen.num = 10;
    queen.id = 'Q';
    king.num = 10;
    king.id = 'K';

    Texture2D aDeck[TEXTURE_COUNT] = {deck.hA, deck.h2, deck.h3, deck.h4, deck.h5, deck.h6, deck.h7, deck.h8, deck.h9, deck.h10, deck.hJ, deck.hQ, deck.hK, deck.cA, deck.c2, deck.c3, deck.c4, deck.c5, deck.c6, deck.c7, deck.c8, deck.c9, deck.c10, deck.cJ, deck.cQ, deck.cK, deck.dA, deck.d2, deck.d3, deck.d4, deck.d5, deck.d6, deck.d7, deck.d8, deck.d9, deck.d10, deck.dJ, deck.dQ, deck.dK, deck.sA, deck.s2, deck.s3, deck.s4, deck.s5, deck.s6, deck.s7, deck.s8, deck.s9, deck.s10, deck.sJ, deck.sQ, deck.sK};

    //--------------------------------------------------------------------------------------

    Image Icon = LoadImage("../img/kicko.png");

    SetWindowIcon(Icon);


    SetTargetFPS(60);   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------


    Rectangle stand = {screenWidth - 120 - 25, 2.2 * screenHeight / 5 - 12.5, 120, 50, (Color) {0, 0, 0, 100}};
    Rectangle hit = {(0 * screenWidth) + 25, 2.2 * screenHeight / 5 - 12.5, 120, 50, (Color) {0, 0, 0, 100}};
    Rectangle start = {(screenWidth / 2) - 375, screenHeight / 2 - 250, 750, 450, (Color) {0, 0, 0, 0}};

    system("echo amogus říká: \"Ahoj\"");

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Start game
        if (IsKeyPressed(KEY_SPACE)) {
            bGame = true;
        }
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), start)) {
            bGame = true;
        }

        // Hit controls
        if (IsKeyPressed(KEY_H) && bStand == false && bGame == true) {
            bStand = false;
            bHit = true;
        }
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), hit) &&
            bStand == false) {
            bStand = false;
            bHit = true;
        }

        // Stand controls
        if (IsKeyPressed(KEY_S) && bHit == false && bGame == true) {
            bHit = false;
            bStand = true;
        }
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), stand) &&
            bHit == false) {
            bHit = false;
            bStand = true;
        }

        if (bGame == true) {
            Start();
            for (int i = 0; i < MAX_SIZE; ++i) {
                printf("%d ", HandMe[i]);
            }
            if (bHit == true && bPlayerTurn == true) {
                Hit();
            }
            else if (bStand == true && bPlayerTurn == true)
            {
                Stand(deck, hit, stand, start, aDeck);
            }


            UpdateDrawFrame(deck, hit, stand, start, aDeck);
        }

    }
        // De-Initialization
        //--------------------------------------------------------------------------------------
        for (int i = 0; i < TEXTURE_COUNT; i++)
            UnloadTexture(aDeck[i]);
        //UnloadTexture(deck.cA);
        CloseWindow();        // Close window and OpenGL context
        //--------------------------------------------------------------------------------------


        return 0;
}

void printout(Cards deck, Rectangle rHit, Rectangle stand, Rectangle start, Texture2D aDeck[TEXTURE_COUNT])
{
    UpdateDrawFrame(deck, rHit, stand, start, aDeck);
}

//----------------------------------------------------------------------------------
// Module Functions Definition
//----------------------------------------------------------------------------------
    void UpdateDrawFrame(Cards deck, Rectangle hit, Rectangle stand, Rectangle start, Texture2D aDeck[TEXTURE_COUNT])
    {

        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        if(bLose)
        {
            DrawText("You lose!", screenWidth / 2 - MeasureText("You lose!", 50) / 2, 1.8 * screenHeight / 5, 50,
                     GOLD);
            sleep(3);
        }
        else if(bWin)
        {
            DrawText("You win!", screenWidth / 2 - MeasureText("You win!", 50) / 2, 1.8 * screenHeight / 5, 50,
                     GOLD);
            sleep(3);
        }

        ClearBackground(DARKERGREEN);

        if (bGame) {
            if(bWin)
            {
                DrawText("You win!", screenWidth / 2 - MeasureText("You win!", 50) / 2, 1.8 * screenHeight / 5, 50,
                         GOLD);
            }
            else if(bLose)
            {
                DrawText("You lose!", screenWidth / 2 - MeasureText("You lose!", 50) / 2, 1.8 * screenHeight / 5, 50,
                         GOLD);
            }
            else {
                DrawText("Blackjack", screenWidth / 2 - MeasureText("Blackjack", 50) / 2, 1.8 * screenHeight / 5, 50,
                         GOLD);
                DrawRectangleRec(hit, (Color) {0, 0, 0, 100});
                DrawText("Hit", (0 * screenWidth) + 25 + 60 - MeasureText("Hit", 30) / 2, 2.2 * screenHeight / 5, 30,
                         GOLD);
                DrawText("OR", screenWidth / 2 - MeasureText("OR", 30) / 2, 2.2 * screenHeight / 5, 30, GOLD);
                DrawRectangleRec(stand, (Color) {0, 0, 0, 100});
                DrawText("Stand", (screenWidth - MeasureText("Stand", 30) / 2) - 25 - 60, 2.2 * screenHeight / 5, 30,
                         GOLD);

                if (bHit) {
                    DrawText("You hit!", screenWidth / 2 - MeasureText("You hit!", 30) / 2, 2.2 * screenHeight / 5 + 50,
                             30,
                             GOLD);
                    bHit = false;
                } else if (bStand) {
                    DrawText("You stand!", screenWidth / 2 - MeasureText("You stand!", 30) / 2,
                             2.2 * screenHeight / 5 + 50,
                             30, GOLD);
                    bStand = false;
                }

                for (int i = 0; i <= cardNumMe-1; i++)
                {
                    DrawTextureEx(aDeck[HandMe[i]-1], (Vector2) {(i+2)*screenWidth / (3+cardNumMe) - aDeck[HandMe[i]-1].width / 2, 450}, 0, 1,WHITE);
                }

                for (int i = 0; i <= cardNumHouse-1; i++)
                {
                    DrawTextureEx(aDeck[HandHouse[i]-1], (Vector2) {(i+2)*screenWidth / (3+cardNumHouse) - SCALE*(aDeck[HandHouse[i]-1].width / 2), 50}, 0, SCALE,WHITE);
                }
/*
                DrawTextureEx(deck.cA, stul.K1, 0, SCALE, WHITE);
                DrawTextureEx(deck.backfaceR, stul.K2, 0, SCALE, WHITE);

                DrawTextureEx(deck.backfaceB, stul.H1, 0, 1, WHITE);
                DrawTextureEx(deck.c9, stul.H2, 0, 1, WHITE);
                DrawTextureEx(deck.cK, stul.H3, 0, 1, WHITE);
                */
            }
        } else {
            DrawTextureEx(deck.backfaceR, (Vector2) {screenWidth / 2 - (SCALE * deck.backfaceB.width / 2) + 90,
                                                     screenHeight / 2 - (SCALE * deck.backfaceB.height / 2) - 105}, 25,
                          SCALE, WHITE);
            DrawTextureEx(deck.backfaceB, (Vector2) {screenWidth / 2 - (SCALE * deck.backfaceB.width / 2) - 90,
                                                     screenHeight / 2 - (SCALE * deck.backfaceB.height / 2) - 55}, -25,
                          SCALE, WHITE);
            DrawText("Blackjack", 2 * screenWidth / 5, 2.55 * screenHeight / 5, 50, GOLD);
            DrawText("Press space to start", screenWidth / 2 - MeasureText("Press space to start", 50) / 2,
                     2.55 * screenHeight / 5 + 50, 50, GOLD);
            DrawRectangleRec(start, (Color) {0, 0, 0, 0});
        }

        if(bWin || bLose)
        {
            DrawText("Press space to play again", screenWidth / 2 - MeasureText("Press space to play again", 50) / 2,
                     2.55 * screenHeight / 5 + 50, 50, GOLD);
            DrawRectangleRec(start, (Color) {0, 0, 0, 0});
        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }