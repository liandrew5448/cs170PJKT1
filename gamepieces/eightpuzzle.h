#pragma once
#ifndef EightPuzzle_h
#define EightPuzzle_h
#include <string>

using namespace std;

class EightPuzzle {
private:
    int board[3][3];
    int cost; // Cost to reach the current state
public:
    EightPuzzle(); // Default constructor & generates goal state
    const int (&getBoard() const)[3][3];  // Returns the value at a specific board
    void setBoard(const int newBoard[3][3]); // Sets the board to a specific configuration
    int moveUp();    // Moves the blank tile up
    int moveDown();  // Moves the blank tile down
    int moveLeft();  // Moves the blank tile left
    int moveRight(); // Moves the blank tile right
    void printBoard() const; // Prints the current state of the board
    bool isGoalState() const; // Checks if the current state is the goal state
    void setCost(int newCost) { cost = newCost; } // Sets the cost to reach the current state
    int getCost() const { return cost; } // Gets the cost to reach the current
};

#endif