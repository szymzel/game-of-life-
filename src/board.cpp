#include "board.h"
#include <vector>

board::board(int width, int height) : 
width(width), height(height), 
grid(height*width,0) {
};

int board::index(int x, int y) const{
    return y*width + x;
}
/*
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
*/

void board::setCell(int x, int y, int value){
    if (x<0 || x>=width || y<0 || y>=height){
        return;
    }
    grid[this->index(x,y)] = value;
}

int board::getWidth() const{
    return width;
}

int board::getHeight() const{
    return height;
}

int board::getCell(int x, int y) const{
    if (x<0 || x>=width || y<0 || y>=height){
        return 0;
    }
    return grid[this->index(x,y)];
}

