#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include "GameOfLife.h"

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    for (const auto& element : v){
        os << element << " ";
    }
    return os;
}

const int W = 100;
const int H = 25;

void draw(const GameOfLife& game){
    std::cout << "\033[H\033[2J\033[3J";
    for (int i = 0; i<game.getHeight();i++){
        for (int j=0; j<game.getWidth();j++){
            int cell = game.getCell(j,i);
            std::cout << (cell!=0 ? "#" : ".");
        }
        std::cout<<"\n";
    }
    std::cout.flush();
}

void InitialConditions(GameOfLife& game){
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
}
int main(){
    GameOfLife game(W,H);
    InitialConditions(game);

    int liczba_generacji = 500;
    for (int i = 0;i<liczba_generacji;i++){
        
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
        draw(game);
        game.update();

    }


}