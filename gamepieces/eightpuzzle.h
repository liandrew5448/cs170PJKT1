#define eightpuzzle_h
#include <string>

using namespace std;

class EightPuzzle {
private:
    int board[3][3];
public:
    EightPuzzle(); // Default constructor & generates goal state
    const int (&getBoard() const)[3][3];  // Returns the value at a specific board
    void setBoard(const int newBoard[3][3]); // Sets the board to a specific configuration
    void moveUp();    // Moves the blank tile up
    void moveDown();  // Moves the blank tile down
    void moveLeft();  // Moves the blank tile left
    void moveRight(); // Moves the blank tile right
    void printBoard() const; // Prints the current state of the board
    bool isGoalState() const; // Checks if the current state is the goal state
};