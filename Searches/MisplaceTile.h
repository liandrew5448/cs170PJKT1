#include "../gamepieces/EightPuzzle.h"
#ifndef MISPLACETILE_H
#define MISPLACETILE_H

class MisplaceTile {
    public:
        MisplaceTile();
        EightPuzzle solve(EightPuzzle& initialState);
    private: 
        void applyAMT(EightPuzzle& node, vector<EightPuzzle>& que); //applies A* Misplace Tile to the queue
};

#endif 