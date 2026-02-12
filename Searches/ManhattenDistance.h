#include "../gamepieces/EightPuzzle.h"
#ifndef MISPLACETILE_H
#define MISPLACETILE_H

class ManhattenDistance {
    public:
        ManhattenDistance();
        EightPuzzle solve(EightPuzzle& initialState);
};

#endif