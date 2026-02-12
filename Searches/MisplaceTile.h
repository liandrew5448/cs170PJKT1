#include "../gamepieces/EightPuzzle.h"
#ifndef MISPLACETILE_H
#define MISPLACETILE_H

class MisplaceTile {
    public:
        MisplaceTile();
        EightPuzzle solve(EightPuzzle& initialState);
};

#endif 