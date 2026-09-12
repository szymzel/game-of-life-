# Game of Life

C++17 cellular automaton simulator rendered with raylib. Implements Conway's Game of Life (B3/S23) and Seeds (B2/S) behind a common `cellular_automaton` interface.

## Requirements

- C++17 compiler (`clang++`)
- raylib (`brew install raylib` on macOS)
- `pkg-config`

## Build

```sh
make
```

## Run

```sh
make go
# or
./game
```

## Controls

- Hold left mouse button: set live cells under the cursor
- Space: pause/resume

## Structure

```
src/
├── main.cpp                    # window init, main loop
├── board.h / board.cpp         # grid storage (flat int vector), bounds-checked get/set
├── cellular_automaton.h / .cpp # interface: update(board&), neighbours()
├── automata/
│   ├── game_of_life.h / .cpp
│   └── seeds.h / .cpp
├── renderer.h / renderer.cpp   # draws the board
├── input.h / input.cpp         # mouse/keyboard handling
└── initial_conditions.h / .cpp # starting patterns (Acorn, Pulsar, R-pentomino, random, ...)
```

Each `update()` reads from the board and writes to a separate copy, which is then swapped in, so all cells update against the same previous-generation state.
