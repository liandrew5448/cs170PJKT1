#define UniformCostSearch_h
#include "../gamepieces/EightPuzzle.h"
#include <vector>
#include <iostream>

class UniformCostSearch {
public:
    UniformCostSearch(); //constructor
    EightPuzzle solve(EightPuzzle& puzzle); //solves the puzzle and returns solution state if exitst
private:
    void applyUCS(EightPuzzle& node, vector<EightPuzzle>& que); //applies uniform cost search to the queue
};