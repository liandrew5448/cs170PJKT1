#include "../gamepieces/EightPuzzle.h"
#include <vector>
#include <iostream>
#ifndef MISPLACETILE_H
#define MISPLACETILE_H

class ManhattenDistance {
    public:
        ManhattenDistance();
        EightPuzzle solve(EightPuzzle& initialState);
        int size() const {return totalNodes;}; //returns total nodes expanded
    private:
        void applyAMD(EightPuzzle& node, vector<EightPuzzle>& que); //applies A* Manhatten Distance to the queue
        int totalNodes = 0; //tracks total nodes expanded
};

#endif