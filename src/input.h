#pragma once
#include "GameOfLife.h"
#include "renderer.h"

void LittleBoom(GameOfLife& game, int cellSize);

void DrawBlackSquare(GameOfLife&game, int cellSize, int size);

void BigBoom(GameOfLife& game, int cellSize, int range);

void ConstSource(GameOfLife& game, int cellSize, int size);

void handleInput(GameOfLife& game, int cellSize);

void Pause(bool& IsPaused);