#include "input.h"
#include "raylib.h"
#include "board.h"
#include "renderer.h"

void LittleBoom(board& grid, int cellSize){
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        int posx = GetMouseX();
        int posy = GetMouseY();
        //przeliczam jaka to jest komorka i zapalam
        int x = posx/cellSize;
        int y = posy/cellSize;
        grid.setCell(x,y,1);
        grid.setCell(x+1,y,1);
        grid.setCell(x-1,y,1);
        grid.setCell(x,y+1,1);
        grid.setCell(x,y-1,1);
    }
}

void DrawBlackSquare(board& grid, int cellSize, int size){
    int range = size/2;
    int posx = GetMouseX();
        int posy = GetMouseY();
        int x = posx/cellSize;
        int y = posy/cellSize;
        for(int i = 0;i<range;i++){
            for (int j =0;j<range;j++){
                grid.setCell(x-i,y-j,1);
                grid.setCell(x+i,y-j,1);
                grid.setCell(x-i,y+j,1);
                grid.setCell(x+i,y+j,1);
            }
        }
}

void BigBoom(board& grid, int cellSize, int size){
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        DrawBlackSquare(grid, cellSize, size);
    }

}

void ConstSource(board& grid, int cellSize, int size){
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
        DrawBlackSquare(grid, cellSize, size);
    }
}
void handleInput(board& grid, int cellSize){

    ConstSource(grid, cellSize, 10);
}

void Pause(bool& IsPaused){
    if (IsKeyPressed(KEY_SPACE)&&IsPaused==1){
        IsPaused = 0;
    } else if(IsKeyPressed(KEY_SPACE)&&IsPaused==0){
        IsPaused = 1;
    }
}