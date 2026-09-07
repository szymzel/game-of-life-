#include <iostream>
#include <vector>
#include <string>
#include "raylib.h"
#include "renderer.h"
#include "GameOfLife.h"
#include "input.h"
#include "InitialConditions.h"

const int W = 240*5;
const int H = 160*5;
const int cellSize = 1;
bool IsPaused = 0;

int main(){
    InitWindow(W*cellSize,H*cellSize, "GameOfLife");
    SetTargetFPS(60);
    GameOfLife game(W,H);
    InitialConditions(game);
    int GenerationNumber = 0;
    while (!WindowShouldClose()){
        handleInput(game, cellSize);
        Pause(IsPaused);
        if (IsPaused==0){
            game.update();
            GenerationNumber += 1;
        }

        std::string text = "Generation number: " + std::to_string(GenerationNumber);

        BeginDrawing();
        ClearBackground(BLACK);
        draw(game,cellSize);
        DrawText(text.c_str(),0,0,16,LIME);
        EndDrawing();
    }

    CloseWindow();
    return 0;

}