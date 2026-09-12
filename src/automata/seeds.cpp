#include "../cellular_automaton.h"
#include "../board.h"
#include "seeds.h"
#include <string>

seeds::seeds(std::string name): cellular_automaton(name){}

void seeds::update(board& grid){
    board next(grid);
    for (int i =0; i<grid.getWidth();i++){
        for (int j = 0;j<grid.getHeight();j++){
            int n = this->neighbours(grid,i,j);
            next.setCell(i,j,0);
            if (grid.getCell(i,j)==0 && n==2){
                next.setCell(i,j,1);
            }
        }
    }
    grid = next;
}