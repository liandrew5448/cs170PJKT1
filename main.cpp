#include <iostream>
#include "gamepieces/eightpuzzle.h"
using namespace std;

int main() {
    EightPuzzle puzzle;
    cout << "Initial State:" << endl;
    puzzle.printBoard();
    cout << "Solving using:" << endl;
    cout << "[insert search method here]" << endl;
    return 0;
}
