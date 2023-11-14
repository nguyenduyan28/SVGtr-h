#include "header.h"
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1200;
    const int screenHeight = 700;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    // Detect window close button or ESC key
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        RectangleSVG rec;
        rec.getData();
        rec.drawRectangleSVG();
        PolygonSVG p;
        p.getData();
        p.drawPolygonSVG();
        Vector2 temp;
        temp.x = 100;
        temp.y = 200;
        EllipseSVG e;
        e.getData();
        e.drawEllipseSVG();
        EndDrawing();
    }
        //----------------------------------------------------------------------------------

    // De-Initialization
    //--------------------------------------------------------------------------------------       // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}