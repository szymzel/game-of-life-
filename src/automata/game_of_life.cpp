#include "game_of_life.h"
#include "../board.h"
#include "../cellular_automaton.h"
#include <string>


game_of_life::game_of_life(std::string name) : cellular_automaton(name){}

void game_of_life::update(board& grid){
    
   board next(grid);
   for (int i = 0; i<grid.getWidth();i++){
    for (int j =0;j<grid.getHeight();j++){
        int n = this->neighbours(grid,i,j);
        if (grid.getCell(i,j) == 1){
            if(n==2 || n==3){
                continue;
            } else if (n<2){
                next.setCell(i,j,0);
            } else if (n>3){
                next.setCell(i,j,0);
            }
        } else if (grid.getCell(i,j) == 0){
            if (n == 3){
                next.setCell(i,j,1);
            }
        }
    }
   }
   grid = next;
}