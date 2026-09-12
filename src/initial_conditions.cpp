#include "board.h"
#include "initial_conditions.h"
#include <random>


void AllColoredBoard(board& grid){
    for (int i = 0;i<grid.getWidth();i++){
        for (int j = 0;j<grid.getHeight();j++){
            grid.setCell(i,j,1);
        }
    }
}


void DefaultScenario(board& grid){
    grid.setCell(26,2,1);

    grid.setCell(24,3,1);
    grid.setCell(26,3,1);

    grid.setCell(14,4,1);
    grid.setCell(15,4,1);
    grid.setCell(22,4,1);
    grid.setCell(23,4,1);
    grid.setCell(36,4,1);
    grid.setCell(37,4,1);

    grid.setCell(13,5,1);
    grid.setCell(17,5,1);
    grid.setCell(22,5,1);
    grid.setCell(23,5,1);
    grid.setCell(36,5,1);
    grid.setCell(37,5,1);

    grid.setCell(2,6,1);
    grid.setCell(3,6,1);
    grid.setCell(12,6,1);
    grid.setCell(18,6,1);
    grid.setCell(22,6,1);
    grid.setCell(23,6,1);

    grid.setCell(2,7,1);
    grid.setCell(3,7,1);
    grid.setCell(12,7,1);
    grid.setCell(16,7,1);
    grid.setCell(18,7,1);
    grid.setCell(19,7,1);
    grid.setCell(24,7,1);
    grid.setCell(26,7,1);

    grid.setCell(12,8,1);
    grid.setCell(18,8,1);
    grid.setCell(26,8,1);

    grid.setCell(13,9,1);
    grid.setCell(17,9,1);

    grid.setCell(14,10,1);
    grid.setCell(15,10,1);

    // R-pentomino, daleko od działka - chaotyczna ewolucja przez setki generacji
    grid.setCell(101,40,1);
    grid.setCell(102,40,1);
    grid.setCell(100,41,1);
    grid.setCell(101,41,1);
    grid.setCell(101,42,1);
}

void Acorn(board& grid){
    grid.setCell(31,100,1);

    grid.setCell(33,101,1);

    grid.setCell(30,102,1);
    grid.setCell(31,102,1);
    grid.setCell(34,102,1);
    grid.setCell(35,102,1);
    grid.setCell(36,102,1);
}

void Pulsar(board& grid){
    grid.setCell(182,100,1);
    grid.setCell(183,100,1);
    grid.setCell(184,100,1);
    grid.setCell(188,100,1);
    grid.setCell(189,100,1);
    grid.setCell(190,100,1);

    grid.setCell(180,102,1);
    grid.setCell(185,102,1);
    grid.setCell(187,102,1);
    grid.setCell(192,102,1);

    grid.setCell(180,103,1);
    grid.setCell(185,103,1);
    grid.setCell(187,103,1);
    grid.setCell(192,103,1);

    grid.setCell(180,104,1);
    grid.setCell(185,104,1);
    grid.setCell(187,104,1);
    grid.setCell(192,104,1);

    grid.setCell(182,105,1);
    grid.setCell(183,105,1);
    grid.setCell(184,105,1);
    grid.setCell(188,105,1);
    grid.setCell(189,105,1);
    grid.setCell(190,105,1);

    grid.setCell(182,107,1);
    grid.setCell(183,107,1);
    grid.setCell(184,107,1);
    grid.setCell(188,107,1);
    grid.setCell(189,107,1);
    grid.setCell(190,107,1);

    grid.setCell(180,108,1);
    grid.setCell(185,108,1);
    grid.setCell(187,108,1);
    grid.setCell(192,108,1);

    grid.setCell(180,109,1);
    grid.setCell(185,109,1);
    grid.setCell(187,109,1);
    grid.setCell(192,109,1);

    grid.setCell(180,110,1);
    grid.setCell(185,110,1);
    grid.setCell(187,110,1);
    grid.setCell(192,110,1);

    grid.setCell(182,112,1);
    grid.setCell(183,112,1);
    grid.setCell(184,112,1);
    grid.setCell(188,112,1);
    grid.setCell(189,112,1);
    grid.setCell(190,112,1);
}

void GliderGun(board& grid){
    grid.setCell(34,10,1);

    grid.setCell(32,11,1);
    grid.setCell(34,11,1);

    grid.setCell(22,12,1);
    grid.setCell(23,12,1);
    grid.setCell(30,12,1);
    grid.setCell(31,12,1);
    grid.setCell(44,12,1);
    grid.setCell(45,12,1);

    grid.setCell(21,13,1);
    grid.setCell(25,13,1);
    grid.setCell(30,13,1);
    grid.setCell(31,13,1);
    grid.setCell(44,13,1);
    grid.setCell(45,13,1);

    grid.setCell(10,14,1);
    grid.setCell(11,14,1);
    grid.setCell(20,14,1);
    grid.setCell(26,14,1);
    grid.setCell(30,14,1);
    grid.setCell(31,14,1);

    grid.setCell(10,15,1);
    grid.setCell(11,15,1);
    grid.setCell(20,15,1);
    grid.setCell(24,15,1);
    grid.setCell(26,15,1);
    grid.setCell(27,15,1);
    grid.setCell(32,15,1);
    grid.setCell(34,15,1);

    grid.setCell(20,16,1);
    grid.setCell(26,16,1);
    grid.setCell(34,16,1);

    grid.setCell(21,17,1);
    grid.setCell(25,17,1);

    grid.setCell(22,18,1);
    grid.setCell(23,18,1);
}

void Random(board& grid){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0,99);
    for (int x = 0; x < grid.getWidth(); x++){
        for (int y = 0; y < grid.getHeight(); y++){
            if (dist(gen) < 25){
                grid.setCell(x, y, 1);
            }
        }
    }
}
