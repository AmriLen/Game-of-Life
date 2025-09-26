# Game of Life
A small program written as part of my studies

The program is written in the C programming language using the `ncurses` library.

<img width="799" height="569" alt="game_of_life_preview" src="https://github.com/user-attachments/assets/9cb1ea67-6fed-4875-98e0-c9095e51287d" />

## About game
John Conway's Game of Life is a playerless game where you set the initial state, and the game automatically calculates the next generation.

Brief Rules:
- Each living cell has 8 neighbors;
- A cell is alive if it has 2 or 3 living neighbors;
- A dead cell revives if it has exactly 3 living neighbors;
- Otherwise, cells die: from loneliness (fewer than 2 living neighbors) or overcrowding (more than 3 living neighbors).

The game takes place on an infinite two-dimensional grid of cells, each of which can be alive or dead, and evolves according to these simple rules.

## Task

Develop an src/game_of_life.c program in C – a visualization of The Game of Life. To display the graphics, only use ASCII characters (with output to the terminal). You need to implement interactive version of the Game of life. Also create the options for adjusting the speed of the "game" and the ability to finish it. Library `ncurses` can be used to simplify the processing of the players' actions and displaying symbolic graphics.

### Graphics

Treat the playing field - a rectangle of 80 by 25 cells – as a matrix of the state of the "game".
It is assumed that the field is "closed to itself", for example, in the lower right square, the neighbor on the right is the lower left square, and the neighbor on the bottom is the upper right.
Provide for original initialization of the "game" state via stdin. Prepare at least 5 files with initial states for quick launch and initialization through input redirection.

### Keys

- A/Z to increase/decrease speed respectively

- Space Bar to terminate the game

### Important notes

- The game must be written in C, have a structured style, and run from the terminal;

- Your source code will be tested by the static analyzer ```cppcheck```, as well as the style linter ```clang-format```;

- Do not use cumbersome functions, the number of lines in the function should not exceed 42;

- Check your program for memory leaks!;

- It is forbidden to make system calls using the system() function and other similar functions that can access the system kernel directly. This prohibition applies to all subsequent quests.

## Start

1. Clone the repository or download the src archive and unzip it into directories of your choice.

2. Compile game_of_life.c using gcc:
   ```
   gcc game_of_life.c -o game_of_life -lncurses
   ```

3. Launch the game via input redirection (you can use any of the suggested templates, or create your own based on them):
   ```
   ./game_of_life < gun.txt
   ```

4. Enjoy the simulation)
