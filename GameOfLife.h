#pragma once
#include <vector>

class GameOfLife{
    public:
        GameOfLife(int width, int height);
        void update();
        void setCell(int x ,int y, int value);
        int getWidth() const;
        int getHeight() const;
        int getCell(int x, int y) const;
    private:
        int width;
        int height;
        std::vector<std::vector<int>> board;
};
