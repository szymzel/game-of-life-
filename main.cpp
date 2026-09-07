#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include "raylib.h"
#include "renderer.h"
#include "GameOfLife.h"
#include "input.h"
#include "InitialConditions.h"

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    for (const auto& element : v){
        os << element << " ";
    }
    return os;
}

const int W = 120;
const int H = 80;
const int cellSize = 10;
bool IsPaused = 0;

/*
void draw(const GameOfLife& game){
    std::cout << "\033[H\033[2J\033[3J";
    for (int i = 0; i<game.getHeight();i++){
        for (int j=0; j<game.getWidth();j++){
            int cell = game.getCell(j,i);
            std::cout << (cell!=0 ? "#" : ".");
        }
        std::cout<<"\n";
    }
    std::cout.flush();
}
*/

int main(){
    InitWindow(W*cellSize,H*cellSize, "GameOfLife");
    SetTargetFPS(60);
    GameOfLife game(W,H);
    InitialConditions(game);
    /*
    int liczba_generacji = 500;
    for (int i = 0;i<liczba_generacji;i++){
        
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
        draw(game, cellSize);
        game.update();

    }
    */

    while (!WindowShouldClose()){
        handleInput(game, cellSize);
        Pause(IsPaused);
        if (IsPaused==0){
            game.update();
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);
        draw(game,cellSize);
        EndDrawing();
    }

    CloseWindow();
    return 0;

}