#pragma once
#include "cellular_automaton.h"
#include "board.h"
#include <string>

class game_of_life : public cellular_automaton{
    public:
        game_of_life(std::string name);
        void update(board& grid);
};

