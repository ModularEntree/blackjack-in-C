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

//----------------------------------------------------------------------------------
// Global Variables Definition
//----------------------------------------------------------------------------------
int screenWidth = 1280;
int screenHeight = 720;

//----------------------------------------------------------------------------------
// Module Functions Declaration
//----------------------------------------------------------------------------------
void UpdateDrawFrame(Texture2D Tcheckerboard);     // Update and Draw one frame

//----------------------------------------------------------------------------------
// Main Enry Point
//----------------------------------------------------------------------------------
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    //LoadFontFromImage((image){"resources/alagard.png"});
    Texture2D Tcheckerboard = LoadTexture("../img/Sedma.png");



    SetTargetFPS(60);   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        UpdateDrawFrame(Tcheckerboard);
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(Tcheckerboard);
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------


    return 0;
}

//----------------------------------------------------------------------------------
// Module Functions Definition
//----------------------------------------------------------------------------------
void UpdateDrawFrame(Texture2D Tcheckerboard)
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
    DrawTextureV(Tcheckerboard,(Vector2) {screenWidth/1.5-Tcheckerboard.width, screenHeight/1.5-Tcheckerboard.height}, WHITE);
        //DrawTextureRec(Tcheckerboard, (Rectangle){0, 0, 100, 100}, (Vector2){screenWidth/2-50, screenHeight/2-50}, WHITE);




        EndDrawing();
    //----------------------------------------------------------------------------------
}