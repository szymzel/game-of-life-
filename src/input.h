#pragma once
#include "board.h"
#include "renderer.h"

void LittleBoom(board& grid, int cellSize);

void DrawBlackSquare(board&grid, int cellSize, int size);

void BigBoom(board& grid, int cellSize, int range);

void ConstSource(board& grid, int cellSize, int size);

void handleInput(board& grid, int cellSize);

void Pause(bool& IsPaused);