#include <iostream>
#include <vector>
#include <string>
#include "raylib.h"
#include "renderer.h"
#include "board.h"
#include "input.h"
#include "initial_conditions.h"
#include "automata/game_of_life.h"
#include "automata/seeds.h"
#include "automata/high_life.h"

const int W = 200;
const int H = 130;
const int cellSize = 6;

bool IsPaused = 0;

int main(){

    std::unique_ptr<cellular_automaton> automaton = std::make_unique<high_life>("High Life");



    std::string name = automaton->getName();
    InitWindow(W*cellSize,H*cellSize, name.c_str());
    SetTargetFPS(60);
    board grid(W,H);
    Random(grid);
    int GenerationNumber = 0;
    while (!WindowShouldClose()){
        handleInput(grid, cellSize);
        Pause(IsPaused);
        if (IsPaused==0){
            automaton->update(grid);
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