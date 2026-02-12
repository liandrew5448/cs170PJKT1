#include "UniformCostSearch.h"
#include <vector>
#include <iostream>

UniformCostSearch::UniformCostSearch() {
    // empty constructor
}

EightPuzzle UniformCostSearch::solve(EightPuzzle& initialState) {
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
            cout << "Flag1" << endl;
            if (node.isGoalState() == true) //if problem.Goal-TEST(node.STATE) succeeds then return
            {
                cout << "success" << endl;
                return node;
            }

            //nodes = queueing-FUNCTION(nodes, EXPAND(node, problem.OPERATORS))
            EightPuzzle childState = node; 

            if (childState.moveUp() == 0) 
            {
                childState.applyUCS(childState, que);
                childState = node; 
            }


            if (childState.moveDown() == 0) 
            {
                childState.applyUCS(childState, que);
                childState = node; 
            }

            if (childState.moveLeft() == 0) 
            {
                childState.applyUCS(childState, que);
                childState = node; 
            }

            if (childState.moveRight() == 0) 
            {
                childState.applyUCS(childState, que);
            }

            visited.push_back(node); //add node to visited list
        }
        cout << "Flag2" << endl;
    }
    cout << "failure" << endl; //if EMPTY(nodes) then return failure
    return initialState;
}

void UniformCostSearch::applyUCS(EightPuzzle& node, vector<EightPuzzle>& que) {
    //search through queue and insert based on f(n) = g(n) + h(n) but uniform cost so h(n) = 0 and g(n) in this puzzle is always 1
    node.setCost(node.getCost() + 1);
    for (auto curr = que.begin(); curr != que.end(); curr++) 
    {
        if (curr->getCost() > node.getCost()) 
        {
            que.insert(curr, node);
            return;
        }
    }
    que.push_back(node);
}
