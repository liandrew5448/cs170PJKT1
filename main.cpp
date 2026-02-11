#include <iostream>
#include "gamepieces/eightpuzzle.h"
#include "Searches/UniformCostSearch.h"
#include "Searches/MisplaceTile.h"
#include "Searches/ManhattenDistance.h"
using namespace std;

int main() {

    //Create eightpuzzle object and give initial state
    EightPuzzle puzzle;    
    int initialBoard[3][3] = {
        {1, 2, 3},
        {4, 0, 5},
        {7, 8, 6}
    };
    puzzle.setBoard(initialBoard);
    cout << "Initial State:" << endl;
    puzzle.printBoard();

    //Create which search method to solve the puzzle


    /* Tests
    if(puzzle.isGoalState()) {
        cout << "work" << endl;
    } else {
        cout << "Not work." << endl;
    }
    cout << "Custom State:" << endl;
    puzzle.printBoard();
    if(puzzle.isGoalState()) {
        cout << "Not work" << endl;
    } else {
        cout << "work." << endl;
    }*/



    /*
    cout << "Solving using:" << endl;
    cout << "[insert search method here]" << endl;*/

    return 0;
}
