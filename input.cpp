#include "input.h"
#include "raylib.h"
#include "GameOfLife.h"
#include "renderer.h"

void LittleBoom(GameOfLife& game, int cellSize){
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        int posx = GetMouseX();
        int posy = GetMouseY();
        //przeliczam jaka to jest komorka i zapalam
        int x = posx/cellSize;
        int y = posy/cellSize;
        game.setCell(x,y,1);
        game.setCell(x+1,y,1);
        game.setCell(x-1,y,1);
        game.setCell(x,y+1,1);
        game.setCell(x,y-1,1);
    }
}

void DrawBlackSquare(GameOfLife&game, int cellSize, int size){
    int range = size/2;
    int posx = GetMouseX();
        int posy = GetMouseY();
        int x = posx/cellSize;
        int y = posy/cellSize;
        for(int i = 0;i<range;i++){
            for (int j =0;j<range;j++){
                game.setCell(x-i,y-j,1);
                game.setCell(x+i,y-j,1);
                game.setCell(x-i,y+j,1);
                game.setCell(x+i,y+j,1);
            }
        }
}

void BigBoom(GameOfLife& game, int cellSize, int size){
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        DrawBlackSquare(game, cellSize, size);
    }

}

void ConstSource(GameOfLife& game, int cellSize, int size){
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
        DrawBlackSquare(game, cellSize, size);
    }
}
void handleInput(GameOfLife& game, int cellSize){

    ConstSource(game, cellSize, 10);
}

void Pause(bool& IsPaused){
    if (IsKeyPressed(KEY_SPACE)&&IsPaused==1){
        IsPaused = 0;
    } else if(IsKeyPressed(KEY_SPACE)&&IsPaused==0){
        IsPaused = 1;
    }
}