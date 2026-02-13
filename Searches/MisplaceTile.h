#include "../gamepieces/EightPuzzle.h"
#ifndef MISPLACETILE_H
#define MisplaceTile_h
#include <vector>
#include <iostream>

class MisplaceTile {
    public:
        MisplaceTile() {}; //constructor
        EightPuzzle solve(EightPuzzle& initialState);
    private: 
        void applyAMT(EightPuzzle& node, vector<EightPuzzle>& que); //applies A* Misplace Tile to the queue
};

#endif 