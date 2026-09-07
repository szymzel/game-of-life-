SOURCES = main.cpp GameOfLife.cpp InitialConditions.cpp renderer.cpp input.cpp

game: $(SOURCES)
	clang++ -std=c++17 -Wall $(SOURCES) $(shell pkg-config --cflags --libs raylib) -o game

go: game
	./game