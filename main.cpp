#include <iostream>
#include "gamepieces/EightPuzzle.h"
#include "Searches/UniformCostSearch.h"
#include "Searches/MisplaceTile.h"
#include "Searches/ManhattenDIstance.h"
#include <chrono>
using namespace std;

int main() {

    

    //create eightpuzzle object and give initial state
    EightPuzzle puzzle;    
    int initialBoard[3][3] = {
        {0, 7, 2},
        {4, 6, 1},
        {3, 5, 8}
    };
    
    puzzle.setBoard(initialBoard);
    cout << "Initial State:" << endl;
    puzzle.printBoard();
    
    chrono::steady_clock::time_point start = chrono::steady_clock::now();
    //create which search method to solve the puzzle
    cout << "Uniform Cost Search" << endl;

    UniformCostSearch ucs;
    MisplaceTile amt;
    ManhattenDistance amd;
    puzzle = ucs.solve(puzzle);

    if(puzzle.isGoalState()) {
        cout << "work" << endl;
    } else {
        cout << "Not work." << endl;
    }
    puzzle.printBoard();

    cout << "Total Depth: " << puzzle.getCost() << endl;
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(end - start);
    cout << "Duration of Search: " << time_span.count() << " seconds" << endl;
    cout << "Total Number of Nodes: " << ucs.size() << endl << endl;

    ////////////////////////////////////////////////////////////////////////////////////
    start = chrono::steady_clock::now();
    cout << "A* Missing Tile Search" << endl;
    puzzle.setBoard(initialBoard);
    puzzle.setCost(0);
    puzzle = amt.solve(puzzle);

    if(puzzle.isGoalState()) {
        cout << "work" << endl;
    } else {
        cout << "Not work." << endl;
    }
    puzzle.printBoard();
    cout << "Total Depth: " << puzzle.getCost() << endl;
    end = chrono::steady_clock::now();
    time_span = chrono::duration_cast<chrono::duration<double>>(end - start);
    cout << "Duration of Search: " << time_span.count() << " seconds" << endl;
    cout << "Total Number of Nodes: " << amt.size() << endl << endl;
    /////////////////////////////////////////////////////////////////////////////////////////////

    start = chrono::steady_clock::now();
    cout << "A* Manhattan Distance Search" << endl;
    puzzle.setBoard(initialBoard);
    puzzle.setCost(0);
    puzzle = amd.solve(puzzle);

    if(puzzle.isGoalState()) {
        cout << "work" << endl;
    } else {
        cout << "Not work." << endl;
    }
    puzzle.printBoard();
    cout << "Total Depth: " << puzzle.getCost() << endl;
    end = chrono::steady_clock::now();
    time_span = chrono::duration_cast<chrono::duration<double>>(end - start);
    cout << "Duration of Search: " << time_span.count() << " seconds" << endl;
    cout << "Total Number of Nodes: " << amd.size() << endl;

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
