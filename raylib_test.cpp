#include "raylib.h"

int main(){
    InitWindow(800,450, "test");
    SetTargetFPS(60);

    while (!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Dziala!", 350,200,20, BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
