#pragma once
#ifndef EightPuzzle_h
#define EightPuzzle_h
#include <string>

using namespace std;

class EightPuzzle {
private:
    int board[3][3];
    int cost; //cost to reach the state
    int heuristic; //heuristic value for the state
public:
    EightPuzzle(); //constructor & generates goal state
    const int (&getBoard() const)[3][3];  //return value at specific board
    void setBoard(const int newBoard[3][3]); //sets board to specific configuration
    int moveUp(); 
    int moveDown(); 
    int moveLeft();  
    int moveRight(); 
    void printBoard() const; //prints current state of board
    bool isGoalState() const; //checks if the current state is the goal state
    void setCost(int newCost) { cost = newCost; } //sets the cost to reach the current state
    int getCost() const { return cost; } //gets the cost to reach the current
    void setHeuristic(int newHeuristic) { heuristic = newHeuristic; } //sets the heuristic value for the current state
    int getHeuristic() const { return heuristic; } //gets the heuristic value for the
};

#endif