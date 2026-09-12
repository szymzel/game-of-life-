#include "../board.h"
#include "../cellular_automaton.h"

class seeds: public cellular_automaton{
    public:
        seeds(std::string name);
        void update(board& grid);

};