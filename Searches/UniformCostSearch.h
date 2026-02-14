#define UniformCostSearch_h
#include "../gamepieces/EightPuzzle.h"
#include <vector>
#include <iostream>

class UniformCostSearch {
public:
    UniformCostSearch(); //constructor
    EightPuzzle solve(EightPuzzle& puzzle); //solves the puzzle and returns solution state if exitst
    int size() const { return totalNodes; } //returns total nodes expanded
private:
    void applyUCS(EightPuzzle& node, vector<EightPuzzle>& que); //applies uniform cost search to the queue
    int totalNodes = 0; //tracks total nodes expanded
};