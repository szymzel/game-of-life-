#include "GameOfLife.h"
#include <vector>

GameOfLife::GameOfLife(int width, int height) : 
width(width), height(height), 
board(height, std::vector<int>(width,0)) {
};

void GameOfLife::update(){
    std::vector<std::vector<int>> next(board);
    for (int i = 1;i<height-1;i++){
        for (int j = 1;j<width-1;j++){
            int neighbours = board[i-1][j] + board[i-1][j+1]
            + board[i-1][j-1] + board[i][j+1] + board[i][j-1]
            + board[i+1][j] + board[i+1][j-1] + board[i+1][j+1];


            if (board[i][j]==1){
                if(neighbours<2){
                    next[i][j] = 0;
                } else if(neighbours == 2 || neighbours == 3){
                    continue;
                } else if(neighbours >3){
                    next[i][j] = 0;
                }
            } else {
                if (neighbours==3){
                    next[i][j] = 1;
                }

            }

        }
    }
    board = next;
}

void GameOfLife::setCell(int x, int y, int value){
    board[y][x] = value;
}

int GameOfLife::getWidth() const{
    return width;
}

int GameOfLife::getHeight() const{
    return height;
}

int GameOfLife::getCell(int x, int y) const{
    return board[y][x];
}

