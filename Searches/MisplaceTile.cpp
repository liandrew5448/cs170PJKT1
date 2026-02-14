#include "../gamepieces/EightPuzzle.h"
#include "MisplaceTile.h"
#include <vector>
#include <iostream>


EightPuzzle MisplaceTile::solve(EightPuzzle& initialState) {
    EightPuzzle nodes = initialState; //nodes = MAKE-QUEUE(MAKE-NODE(problem.INITIAL-STATE))
    vector<EightPuzzle> que;         //Initial state is passed in as parameter and set to current state
    que.push_back(nodes); //Add initial state to the queue
    vector<EightPuzzle> visited; //Create a vector to track visited states

    while(que.empty() == false) //loop do (if empty then return failure is at the end)
    {
        EightPuzzle node = que.front(); //node = REMOVE-FRONT(nodes)
        que.erase(que.begin()); 
        bool alreadyVisited = false; //check if node exists already

        for (const auto& visitedNode : visited) 
        {
            bool match = true; //assume it's the same state until find a difference
            for (int i = 0; i < 3; i++) 
            {
                for (int j = 0; j < 3; j++) 
                {
                    if (node.getBoard()[i][j] != visitedNode.getBoard()[i][j]) 
                    {
                        match = false; //if any value is different, it's not the same state
                        //cout << "Flag 4" << endl;
                        break;
                    }
                }
            }
            
            if (match) 
            {
                alreadyVisited = true;
                break;
            }
        }

        if (!alreadyVisited) 
        {
            //cout << "flag 2" << endl;
            if (node.isGoalState() == true) //if problem.Goal-TEST(node.STATE) succeeds then return
            {
                cout << "success" << endl;
                return node;
            }

            //nodes = queueing-FUNCTION(nodes, EXPAND(node, problem.OPERATORS))
            EightPuzzle childState = node; 

            if (childState.moveUp() == 0) 
            {
                this -> applyAMT(childState, que);

                childState = node; 
            }

            childState = node; 

            if (childState.moveDown() == 0) 
            { 
                this -> applyAMT(childState, que);
                childState = node;
            }

            childState = node;

            if (childState.moveLeft() == 0) 
            {
                this -> applyAMT(childState, que);
                childState = node;
            }

            childState = node; 

            if (childState.moveRight() == 0) 
            {
                this -> applyAMT(childState, que);
            }
            visited.push_back(node); //add node to visited list
            
           // cout << node.getCost() << endl;
        }
       // cout << "flag 1" << endl;
    }
    cout << "failure" << endl; //if EMPTY(nodes) then return failure
    return initialState;
}

void MisplaceTile::applyAMT(EightPuzzle& node, vector<EightPuzzle>& que) {
    //search through queue and insert based on f(n) = g(n) + h(n) 
    //h(n) is the number of misplaced tiles

    //calculate h(n)
    EightPuzzle goalState; 
    int misplacedTiles = 0;
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            if (node.getBoard()[i][j] != goalState.getBoard()[i][j])
            {
                misplacedTiles++; 
            }
        }
    }

    node.setCost(node.getCost() + 1); //g(n) is 1 for every move
    node.setHeuristic(node.getCost() + misplacedTiles); //f(n) = g(n) + h(n)

    for (auto curr = que.begin(); curr != que.end(); curr++) 
    {
        if (curr->getHeuristic() > node.getHeuristic()) //select by cheapest heuristic
        {
            que.insert(curr, node);
            this -> totalNodes++; 
            return;
        }
    }
    que.push_back(node);
    this -> totalNodes++; 
    //cout << "Flag 3" << endl;
}
