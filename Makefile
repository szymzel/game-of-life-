SOURCES = src/main.cpp src/GameOfLife.cpp src/InitialConditions.cpp src/renderer.cpp src/input.cpp

game: $(SOURCES)
	clang++ -std=c++17 -Wall $(SOURCES) $(shell pkg-config --cflags --libs raylib) -o game

go: game
	./game