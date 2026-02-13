#include "../gamepieces/EightPuzzle.h"
#ifndef MISPLACETILE_H
#define MisplaceTile_h
#include <vector>
#include <iostream>

class MisplaceTile {
    public:
        MisplaceTile() {}; //constructor
        EightPuzzle solve(EightPuzzle& initialState);
        EightPuzzle size() const (return totalNodes); //returns total nodes expanded
    private: 
        void applyAMT(EightPuzzle& node, vector<EightPuzzle>& que); //applies A* Misplace Tile to the queue
        int totalNodes = 0; //tracks total nodes expanded
};

#endif 