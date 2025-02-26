#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool game_over = false, game_over_1 = false;
int x = 0;
char marker = 'X';
char cpumarker = 'O';
int allowed[] = {1, 2, 3};
char grid[3][3] = { {'.', '.', '.'}, {'.', '.', '.'}, {'.', '.', '.'} };

void player_move() {
    printf("insert x and y coordinates: ");
    while (1) {
        int x_coord, y_coord;
        scanf("%d %d", &x_coord, &y_coord);
        if (grid[x_coord - 1][y_coord - 1] == 'X' || grid[x_coord - 1][y_coord - 1] == 'O') {
            printf("There is a character already there; try again:");
            continue;
        }
        grid[x_coord - 1][y_coord - 1] = marker;
        break;
    }
}

void cpu_move() {
    while (1) {
        int x_rand = rand() % (2 - 0 + 1);
        int y_rand = rand() % (2 - 0 + 1);
        if (grid[x_rand][y_rand] == 'X' || grid[x_rand][y_rand] == 'O') {
            continue;
        }
        grid[x_rand][y_rand] = cpumarker;
        break;
    }
}

void print_table() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

bool check(char mark) {
    int i;
    if ((grid[0][0] == mark && grid[1][1] == mark && grid[2][2] == mark) || (grid[0][2] == mark && grid[1][1] == mark && grid[2][0] == mark)) {
        return true;
    }
    for (i = 0; i < 3; i++) {
        if (grid[i][0] == mark && grid[i][1] == mark && grid[i][2] == mark) {
            return true;
        }
    }
    for (i = 0, i < 3; i++;) {
        if (grid[0][i] == mark && grid[1][i] == mark && grid[2][i] == mark) {
            return true;
        }
    }
    return false;
}

char choose() {
    while (1) {
        printf("choose a character: ");
        scanf("%c", &marker);
        marker = toupper(marker);
        if (marker == 'X' || marker == 'O') {
            system("clear");
            return marker;
        }
        printf("try again; \n");
    }
}

bool play_turn() {
    if (marker == 'X') {
        player_move();
        game_over = check(marker);
        x = x + 1;
        if (x == 5) {
            return true;
        }
        if (game_over == true) {
            system("clear");
            print_table();
            return true;
        }
        cpumarker = 'O';
        marker = 'O';
        cpu_move();
        system("clear");
        print_table();
        game_over = check(cpumarker);
        if (game_over == true) {
            return true;
        }
        marker = 'X';
    }
    else if (marker == 'O') {
        cpumarker = 'X';
        cpu_move();
        system("clear");
        print_table();
        game_over = check(cpumarker);
        if (game_over == true) {
            return true;
        }
        marker = 'O';
        player_move();
        game_over = check(marker);
        x = x + 1;
        if (x == 5) {
            return true;
        }
        if (game_over == true) {
            system("clear");
            print_table();
            return true;
        }
        marker = 'O';
    }
}

void print_result() {
    if (game_over == true) {
        printf("%c won! \n", marker);
        return;
    }
    printf("Draw :( \n");
}

void play_game() {
    choose();
    x = 0;
    char grid[3][3] = { {'.', '.', '.'}, {'.', '.', '.'}, {'.', '.', '.'} };
    while (1) {
        game_over_1 = play_turn();
        if (game_over_1 == true) {
            return;
        }
    }
}

int main() {
    char input;
    while (1) {
        play_game();
        print_result();
        printf("Do you want to play another game? [y/N] ");
        scanf(" %c", &input);
        if (input != 'y') {
            break;
        }
    }
    return 0;
}
