#include "raylib.h"
#include "board.h"
#include "renderer.h"


void draw(const board& grid, int cellSize){
    for (int i = 0;i < grid.getHeight();i++){
        for (int j = 0;j < grid.getWidth();j++){
            int posx = j*cellSize;
            int posy = i*cellSize;
            if(grid.getCell(j,i)==1){
                DrawRectangle(posx, posy, cellSize, cellSize, LIME);
            }
            
        }
    }
}
