#include "raylib.h"
#include "GameOfLife.h"
#include "renderer.h"


void draw(const GameOfLife& game, int cellSize){
    for (int i = 0;i < game.getHeight();i++){
        for (int j = 0;j < game.getWidth();j++){
            int posx = j*cellSize;
            int posy = i*cellSize;
            if(game.getCell(j,i)==1){
                DrawRectangle(posx, posy, cellSize, cellSize, BLACK);
            }
            
        }
    }
}
