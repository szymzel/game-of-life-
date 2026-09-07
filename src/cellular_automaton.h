#pragma once
#include <string>
#include "board.h"
class cellular_automaton{
    public:
        cellular_automaton(std::string name);
        virtual std::string getName() const;
        virtual void update(board& grid) = 0;
        int neighbours(const board& grid, int x, int y) const;
        virtual ~cellular_automaton(){}
    private:
        std::string name;
};