#include <ncurses.h>
#include <stdio.h>

#define MAX_X 25
#define MAX_Y 80

void initNcurses();
void initBoard(int mainBoard[MAX_X][MAX_Y]);
int inputProcess(int *speedRender);
void printBoard(const int mainBoard[MAX_X][MAX_Y], int speedRender);
void updateBoard(int mainBoard[MAX_X][MAX_Y], int tempBoard[MAX_X][MAX_Y]);
int countNeighbors(int x, int y, const int mainBoard[MAX_X][MAX_Y]);

int main() {
    int speedRender = 100;
    int mainBoard[MAX_X][MAX_Y];
    int tempBoard[MAX_X][MAX_Y];
    initNcurses();
    initBoard(mainBoard);

    while (true) {
        printBoard(mainBoard, speedRender);
        if (inputProcess(&speedRender) == 1) {
            break;
        }
        updateBoard(mainBoard, tempBoard);
        napms(speedRender);
    }
    endwin();
    return 0;
}

void initNcurses() {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    timeout(0);
}

void initBoard(int mainBoard[MAX_X][MAX_Y]) {
    for (int x = 0; x < MAX_X; x++) {
        for (int y = 0; y < MAX_Y; y++) {
            int c;
            if ((c = getchar()) != EOF) {
                if (c == '1') {
                    mainBoard[x][y] = 1;
                } else {
                    mainBoard[x][y] = 0;
                }
            }
        }
    }
    if (!freopen("/dev/tty", "r", stdin)) {
        endwin();
    }
}

int inputProcess(int *speedRender) {
    int userInput = getch();
    int is_exit = 0;
    if (userInput == 'a' || userInput == 'A') {
        if (*speedRender > 10) {
            *speedRender -= 10;
        }
    }
    if (userInput == 'z' || userInput == 'Z') {
        if (*speedRender < 5000) {
            *speedRender += 10;
        }
    }
    if (userInput == ' ') {
        is_exit = 1;
    }
    return is_exit;
}

void printBoard(const int mainBoard[MAX_X][MAX_Y], int speedRender) {
    clear();
    mvprintw(0, 10, "A - Faster, Z - Slower, Space - Exit, Current speed - x%.2lf",
             100 / (double)speedRender);
    for (int y = 0; y < MAX_Y + 2; y++) {
        mvaddch(1, y, '-');
        mvaddch(MAX_X + 2, y, '-');
    }

    for (int x = 0; x < MAX_X + 2; x++) {
        mvaddch(x + 1, 0, '|');
        mvaddch(x + 1, MAX_Y + 1, '|');
    }

    for (int x = 0; x < MAX_X; x++) {
        for (int y = 0; y < MAX_Y; y++) {
            if (mainBoard[x][y]) {
                mvaddch(x + 2, y + 1, '0');
            } else {
                mvaddch(x + 2, y + 1, ' ');
            }
        }
    }
    refresh();
}

void updateBoard(int mainBoard[MAX_X][MAX_Y], int tempBoard[MAX_X][MAX_Y]) {
    for (int x = 0; x < MAX_X; x++) {
        for (int y = 0; y < MAX_Y; y++) {
            int neighbors = countNeighbors(x, y, mainBoard);
            tempBoard[x][y] = (neighbors == 3) || (mainBoard[x][y] && neighbors == 2);
        }
    }

    for (int x = 0; x < MAX_X; x++) {
        for (int y = 0; y < MAX_Y; y++) {
            mainBoard[x][y] = tempBoard[x][y];
        }
    }
}

int countNeighbors(int x, int y, const int mainBoard[MAX_X][MAX_Y]) {
    int count = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue;

            int nx = (x + dx + MAX_X) % MAX_X;
            int ny = (y + dy + MAX_Y) % MAX_Y;

            if (mainBoard[nx][ny]) {
                count++;
            }
        }
    }
    return count;
}
