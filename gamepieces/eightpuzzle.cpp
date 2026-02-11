#include "eightpuzzle.h"
#include <iostream>

using namespace std;

EightPuzzle::EightPuzzle() {
    // Initialize the board to the goal state
    int initialBoard[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0} // 0 represents the blank tile
    };
    setBoard(initialBoard);
}

const int (&EightPuzzle::getBoard() const)[3][3] {
    return board;
}

void EightPuzzle::setBoard(const int newBoard[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = newBoard[i][j];
        }
    }
}

void EightPuzzle::moveUp() {
    // Find the blank tile and move it up if possible
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) { // Blank tile found
                if (i > 0) { // Can move up
                    swap(board[i][j], board[i - 1][j]);
                }
                return;
            }
        }
    }
}

void EightPuzzle::moveDown() {
    // Find the blank tile and move it down if possible
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) { // Blank tile found
                if (i < 2) { // Can move down
                    swap(board[i][j], board[i + 1][j]);
                }
                return;
            }
        }
    }
}

void EightPuzzle::moveLeft() {
    // Find the blank tile and move it left if possible
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) { // Blank tile found
                if (j > 0) { // Can move left
                    swap(board[i][j], board[i][j - 1]);
                }
                return;
            }
        }
    }
}

void EightPuzzle::moveRight() {
    // Find the blank tile and move it right if possible
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) { // Blank tile found
                if (j < 2) { // Can move right
                    swap(board[i][j], board[i][j + 1]);
                }
                return;
            }
        }
    }
}

void EightPuzzle::printBoard() const {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool EightPuzzle::isGoalState() const {
    int goalBoard[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}
    };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != goalBoard[i][j]) {
                return false;
            }
        }
    }
    return true;
}

