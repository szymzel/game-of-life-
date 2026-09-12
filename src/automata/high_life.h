#pragma once
#include "../cellular_automaton.h"
#include "../board.h"
#include <string>

class high_life: public cellular_automaton{
    public:
        high_life(std::string name);
        void update(board& grid);
};
