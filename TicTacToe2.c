#include <stdio.h>
#include <stdlib.h>

struct Player {
    char symbol;
    int score;
};

void initializeGrid(char*** grid) {
    *grid = (char**)malloc(3 * sizeof(char));
    for (int i = 0; i < 3; ++i) {
        (grid)[i] = (char)malloc(3 * sizeof(char));
        for (int j = 0; j < 3; ++j) {
            (*grid)[i][j] = ' ';
        }
    }
}

void printGrid(char** grid) {
    printf("-------------\n");
    for (int i = 0; i < 3; ++i) {
        printf("| ");
        for (int j = 0; j < 3; ++j) {
            printf("%c | ", grid[i][j]);
        }
        printf("\n-------------\n");
    }
}

int checkWin(char** grid, char symbol) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; ++i) {
        if ((grid[i][0] == symbol && grid[i][1] == symbol && grid[i][2] == symbol) ||
            (grid[0][i] == symbol && grid[1][i] == symbol && grid[2][i] == symbol)) {
            return 1; // Player wins
        }
    }
    if ((grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol) ||
        (grid[0][2] == symbol && grid[1][1] == symbol && grid[2][0] == symbol)) {
        return 1; // Player wins
    }
    return 0;
}

void deallocateGrid(char** grid) {
    for (int i = 0; i < 3; ++i) {
        free(grid[i]);
    }
    free(grid);
}

int main() {
    char** grid;
    initializeGrid(&grid);
    
    struct Player playerX = {'X', 0};
    struct Player playerO = {'O', 0};
    struct Player* currentPlayer = &playerX;
    
    int row, col, moveCount = 0, isValidMove;
    
    do {
        isValidMove = 0;
        while (!isValidMove) {
            printf("Player %c, enter your move (row and column, 1 to 3): ", currentPlayer->symbol);
            scanf("%d %d", &row, &col);
            if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && grid[row - 1][col - 1] == ' ') {
                grid[row - 1][col - 1] = currentPlayer->symbol;
                isValidMove = 1;
            } else {
                printf("Invalid move. Please try again.\n");
            }
        }
        
        printGrid(grid);
        moveCount++;
        
        if (checkWin(grid, currentPlayer->symbol)) {
            printf("Player %c wins!\n", currentPlayer->symbol);
            currentPlayer->score++;
            break;
        }
        
        if (moveCount == 9) {
            printf("It's a tie!\n");
            break;
        }
        
        currentPlayer = (currentPlayer == &playerX) ? &playerO : &playerX;
        
    } while (1);
    
    printf("Score: Player X - %d, Player O - %d\n", playerX.score, playerO.score);
    
    deallocateGrid(grid);
    
    return 0;
}