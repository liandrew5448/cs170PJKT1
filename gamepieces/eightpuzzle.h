#pragma once
#ifndef EightPuzzle_h
#define EightPuzzle_h
#include <string>

using namespace std;

class EightPuzzle {
private:
    int board[3][3];
    int cost; //cost to reach the state
public:
    EightPuzzle(); //constructor & generates goal state
    const int (&getBoard() const)[3][3];  //return value at specific board
    void setBoard(const int newBoard[3][3]); //sets board to specific configuration
    int moveUp();    //moves blank up
    int moveDown();  //moves blank down
    int moveLeft();  //moves blank  left
    int moveRight(); //moves blank right
    void printBoard() const; //prints the current state of the board
    bool isGoalState() const; //checks if the current state is the goal state
    void setCost(int newCost) { cost = newCost; } //sets the cost to reach the current state
    int getCost() const { return cost; } //gets the cost to reach the current
};

#endif