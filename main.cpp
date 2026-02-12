#include <iostream>
#include "gamepieces/EightPuzzle.h"
#include "Searches/UniformCostSearch.h"
#include "Searches/MisplaceTile.h"
#include "Searches/ManhattenDistance.h"
using namespace std;

int main() {

    //Create eightpuzzle object and give initial state
    EightPuzzle puzzle;    
    int initialBoard[3][3] = {
        {1, 3, 6},
        {5, 0, 7},
        {4, 8, 2}
    };
    puzzle.setBoard(initialBoard);
    cout << "Initial State:" << endl;
    puzzle.printBoard();

    //Create which search method to solve the puzzle
    cout << "Solving using:" << endl;
    cout << "Uniform Cost Search" << endl;

    UniformCostSearch ucs;
    puzzle =ucs.solve(puzzle);

    if(puzzle.isGoalState()) {
        cout << "work" << endl;
    } else {
        cout << "Not work." << endl;
    }
    puzzle.printBoard();

    cout << "Total Depth: " << puzzle.getCost() << endl;

    /*
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
