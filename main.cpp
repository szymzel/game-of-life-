#include <iostream>



int main(){

    std::vector<std::vector<int>> game;

    for (int i = 0; i<=1000;i++){
        std::vector<int> row;
        for (int j = 0; j<1000;j++){
            row.push_back(0);
        }
        game.push_back(row);
    }

    std::cout << 
}