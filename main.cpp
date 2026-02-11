#include <iostream>
#include "eightpuzzle.h"
using namespace std;

int main() {
    // Create an instance of EightPuzzle with a custom board
    int customBoard[3][3] = {
        {1, 2, 3},
        {5, 6, 0},
        {7, 8, 4}
    };
    EightPuzzle puzzle(customBoard);

    // Print the current board state
    cout << "Current Board State:" << endl;
    const int (&board)[3][3] = puzzle.getBoard();
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
