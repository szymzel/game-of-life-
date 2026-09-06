#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    for (const auto& element : v){
        os << element << " ";
    }
    return os;
}

const int W = 100;
const int H = 25;

void draw(const std::vector<std::vector<int>>& board){
    std::cout << "\033[H\033[2J\033[3J";
    for (const auto& row : board){
        for (int cell : row){
            std::cout << (cell != 0 ? '#' : '.');
        }
        std::cout << '\n';
    }
    std::cout.flush();
}

std::vector<std::vector<int>> update(const std::vector<std::vector<int>>& board){
    std::vector<std::vector<int>> next(board);
    for (int i = 1;i<H-1;i++){
        for (int j = 1;j<W-1;j++){
            int neighbours = board[i-1][j] + board[i-1][j+1]
            + board[i-1][j-1] + board[i][j+1] + board[i][j-1]
            + board[i+1][j] + board[i+1][j-1] + board[i+1][j+1];


            if (board[i][j]==1){
                if(neighbours<2){
                    next[i][j] = 0;
                } else if(neighbours == 2 || neighbours == 3){
                    continue;
                } else if(neighbours >3){
                    next[i][j] = 0;
                }
            } else {
                if (neighbours==3){
                    next[i][j] = 1;
                }

            }

        }
    }
    return next;
}

std::vector<std::vector<int>> initial_conditions(){
    std::vector<std::vector<int>> board(H, std::vector<int>(W, 0));
    // Działko Gospera (Gosper glider gun) - co 30 generacji wystrzeliwuje nowego szybowca
    board[2][26] = 1;

    board[3][24] = 1;
    board[3][26] = 1;

    board[4][14] = 1;
    board[4][15] = 1;
    board[4][22] = 1;
    board[4][23] = 1;
    board[4][36] = 1;
    board[4][37] = 1;

    board[5][13] = 1;
    board[5][17] = 1;
    board[5][22] = 1;
    board[5][23] = 1;
    board[5][36] = 1;
    board[5][37] = 1;

    board[6][2] = 1;
    board[6][3] = 1;
    board[6][12] = 1;
    board[6][18] = 1;
    board[6][22] = 1;
    board[6][23] = 1;

    board[7][2] = 1;
    board[7][3] = 1;
    board[7][12] = 1;
    board[7][16] = 1;
    board[7][18] = 1;
    board[7][19] = 1;
    board[7][24] = 1;
    board[7][26] = 1;

    board[8][12] = 1;
    board[8][18] = 1;
    board[8][26] = 1;

    board[9][13] = 1;
    board[9][17] = 1;

    board[10][14] = 1;
    board[10][15] = 1;


    return board;
}
int main(){
    auto game = initial_conditions();
    int liczba_generacji = 500;
    for (int i = 0;i<liczba_generacji;i++){

        std::this_thread::sleep_for(std::chrono::milliseconds(150));
        draw(game);
        game = update(game);
    }


}