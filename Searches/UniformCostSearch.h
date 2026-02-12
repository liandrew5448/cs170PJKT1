#define UniformCostSearch_h
#include "../gamepieces/EightPuzzle.h"
#include <vector>
#include <iostream>

class UniformCostSearch {
public:
    UniformCostSearch(); // Constructor
    EightPuzzle solve(EightPuzzle& puzzle); // Solves the puzzle using uniform cost search
};