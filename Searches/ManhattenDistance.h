#include "../gamepieces/EightPuzzle.h"
#include <vector>
#include <iostream>
#ifndef MISPLACETILE_H
#define MISPLACETILE_H

class ManhattenDistance {
    public:
        ManhattenDistance();
        EightPuzzle solve(EightPuzzle& initialState);
    private:
        void applyAMD(EightPuzzle& node, vector<EightPuzzle>& que); //applies A* Manhatten Distance to the queue
};

#endif