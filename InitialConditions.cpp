#include "GameOfLife.h"
#include "InitialConditions.h"

void BlackBoardWithoutColoredBoundaries(GameOfLife& game){
    for (int i = 1;i<game.getWidth()-1;i++){
        for (int j = 1;j<game.getHeight()-1;j++){
            game.setCell(i,j,1);
        }
    }
}

void AllBlackBoard(GameOfLife& game){
    for (int i = 0;i<game.getWidth();i++){
        for (int j = 0;j<game.getHeight();j++){
            game.setCell(i,j,1);
        }
    }
}

void WhiteBoard(GameOfLife& game){

}

void DefaultScenario(GameOfLife& game){
    game.setCell(26,2,1);

    game.setCell(24,3,1);
    game.setCell(26,3,1);

    game.setCell(14,4,1);
    game.setCell(15,4,1);
    game.setCell(22,4,1);
    game.setCell(23,4,1);
    game.setCell(36,4,1);
    game.setCell(37,4,1);

    game.setCell(13,5,1);
    game.setCell(17,5,1);
    game.setCell(22,5,1);
    game.setCell(23,5,1);
    game.setCell(36,5,1);
    game.setCell(37,5,1);

    game.setCell(2,6,1);
    game.setCell(3,6,1);
    game.setCell(12,6,1);
    game.setCell(18,6,1);
    game.setCell(22,6,1);
    game.setCell(23,6,1);

    game.setCell(2,7,1);
    game.setCell(3,7,1);
    game.setCell(12,7,1);
    game.setCell(16,7,1);
    game.setCell(18,7,1);
    game.setCell(19,7,1);
    game.setCell(24,7,1);
    game.setCell(26,7,1);

    game.setCell(12,8,1);
    game.setCell(18,8,1);
    game.setCell(26,8,1);

    game.setCell(13,9,1);
    game.setCell(17,9,1);

    game.setCell(14,10,1);
    game.setCell(15,10,1);

    // R-pentomino, daleko od działka - chaotyczna ewolucja przez setki generacji
    game.setCell(101,40,1);
    game.setCell(102,40,1);
    game.setCell(100,41,1);
    game.setCell(101,41,1);
    game.setCell(101,42,1);
}

void InitialConditions(GameOfLife& game){
    WhiteBoard(game);
}