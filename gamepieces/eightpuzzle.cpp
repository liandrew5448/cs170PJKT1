#include "eightpuzzle.h"
#include <iostream>

using namespace std;

EightPuzzle::EightPuzzle() {
    //Initialize the board to the goal state
    int initialBoard[3][3] = 
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0} //0 represents the blank tile
    };
    setBoard(initialBoard);
    cost = 0; //Initialize cost to 0
}

const int (&EightPuzzle::getBoard() const)[3][3] {
    return board;
}

void EightPuzzle::setBoard(const int newBoard[3][3]) {
    //sets the board given specific matrix array
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            board[i][j] = newBoard[i][j];
        }
    }
}

int EightPuzzle::moveUp() {
    //Find the blank tile and move up if possible
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            if (board[i][j] == 0) 
            {
                if (i > 0) 
                { // Can move up
                    swap(board[i][j], board[i - 1][j]);
                }
                return 0; //valid move
            }
        }
    }
    return -1; //Invalid move
}

int EightPuzzle::moveDown() {
    //find the blank tile and move down if possible
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            if (board[i][j] == 0) 
            {
                if (i < 2) 
                {  //can move down
                    swap(board[i][j], board[i + 1][j]);
                }
                return 0; //valid move
            }
        }
    }
    return -1; // Invalid move
}

int EightPuzzle::moveLeft() {
    //find the blank tile and move left if possible
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            if (board[i][j] == 0) 
            { // Blank tile 
                if (j > 0) 
                { // Can move left
                    swap(board[i][j], board[i][j - 1]);
                }
                return 0; //valid move
            }
        }
    }
    return -1; //invalid move
}

int EightPuzzle::moveRight() {
    //find the blank tile and move right if possible
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            if (board[i][j] == 0) 
            { //blank tile 
                if (j < 2) 
                { //can move right
                    swap(board[i][j], board[i][j + 1]);
                }
                return 0; //valid move
            }
        }
    }
    return -1; //invalid move
}

void EightPuzzle::printBoard() const {
    //Runs through board and prints each value in a 3x3 format
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool EightPuzzle::isGoalState() const {
    //Checks if current state of board is the solution
    int goalBoard[3][3] = 
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}
    };

    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            if (board[i][j] != goalBoard[i][j]) 
            {
                return false;
            }
        }
    }
    return true;
}

