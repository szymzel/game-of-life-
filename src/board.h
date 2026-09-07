#pragma once
#include <vector>

class board{
    public:
        board(int width, int height);
        //void update();
        void setCell(int x ,int y, int value);
        int getWidth() const;
        int getHeight() const;
        int getCell(int x, int y) const;
    private:
        int width;
        int height;
        std::vector<int> grid;
        int index(int x, int y) const;
};
