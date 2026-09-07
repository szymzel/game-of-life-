#include "cellular_automaton.h"
#include "board.h"
#include <string>

cellular_automaton::cellular_automaton(std::string name) : name(name){}

std::string cellular_automaton::getName() const{
    return name;
}

int cellular_automaton::neighbours(const board& grid, int x, int y) const{
    return grid.getCell(x,y+1) + grid.getCell(x,y-1) +
    grid.getCell(x-1,y) + grid.getCell(x-1,y-1) + grid.getCell(x-1, y+1) +
     grid.getCell(x+1,y) + grid.getCell(x+1,y-1) + grid.getCell(x+1,y+1);
}