#include <iostream>
#include <vector>
#include <string>
#include "raylib.h"
#include "renderer.h"
#include "board.h"
#include "input.h"
#include "InitialConditions.h"

const int W = 240*5;
const int H = 160*5;
const int cellSize = 1;
bool IsPaused = 0;

int main(){
    InitWindow(W*cellSize,H*cellSize, "GameOfLife");
    SetTargetFPS(60);
    board grid(W,H);
    InitialConditions(grid);
    int GenerationNumber = 0;
    while (!WindowShouldClose()){
        handleInput(grid, cellSize);
        Pause(IsPaused);
        if (IsPaused==0){
            //grid.update();
            GenerationNumber += 1;
        }

        std::string text = "Generation number: " + std::to_string(GenerationNumber);

        BeginDrawing();
        ClearBackground(BLACK);
        draw(grid,cellSize);
        DrawText(text.c_str(),0,0,16,LIME);
        EndDrawing();
    }

    CloseWindow();
    return 0;

}