#include "GameOfLife.h"
#include <vector>

GameOfLife::GameOfLife(int width, int height) : 
width(width), height(height), 
board(height*width,0) {
};

int GameOfLife::index(int x, int y) const{
    return y*width + x;
}

void GameOfLife::update(){
    std::vector<int> next(board);
    for (int i = 1;i<width-1;i++){
        for (int j = 1;j<height-1;j++){
            int neighbours = this->getCell(i-1, j) + this->getCell(i-1, j+1)
            + this->getCell(i-1, j-1) + this->getCell(i, j+1) + this->getCell(i, j-1)
            + this->getCell(i+1, j) + this->getCell(i+1, j-1) + this->getCell(i+1, j+1);

            if (this->getCell(i,j)==1){
                if(neighbours<2){
                    next[index(i,j)] = 0;
                } else if(neighbours == 2 || neighbours == 3){
                    continue;
                } else if(neighbours >3){
                    next[index(i,j)] = 0;
                }
            } else {
                if (neighbours==3){
                    next[index(i,j)] = 1;
                }

            } 
        }
    }
    board = next;
}

void GameOfLife::setCell(int x, int y, int value){
    if (x<0 || x>=width || y<0 || y>=height){
        return;
    }
    board[this->index(x,y)] = value;
}

int GameOfLife::getWidth() const{
    return width;
}

int GameOfLife::getHeight() const{
    return height;
}

int GameOfLife::getCell(int x, int y) const{
    return board[this->index(x,y)];
}

