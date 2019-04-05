#include "solver.h"

using namespace ai;

Solver *Solver::_instance = 0;

solution_t Solver::Breadth_First_Search (){
    //Inital node
    Node* node = new Node(Problem::getInitialState(), 0);
    Node* child;

    //Inital Test.
    if( Problem::goalTest(node->getState()) ){
        solution_t result; result.push_back(M_PAIR(0,0));
        return result; //Nothing to be done
    }

    //Add node to the fifo
    get()->frontier.push(node); get()->allNodes.push(node);
    //Empty explored

    //Loop over the problem space.
    while( true ){
        if( get()->frontier.empty() ) return Solution(NULL);
        node = get()->frontier.front(); get()->frontier.pop();
        //Add to explored;
        for(auto action : Problem::actions(node->getState())){
            child = Node::childNode(node, action);
            //Test if the node is not in explored or frontier the
                if( Problem::goalTest(child->getState()) ) return Solution(child);
                get()->frontier.push(child); get()->allNodes.push(node);
        } 
    }

}


solution_t Solver::Solution (const Node* node){
    solution_t solution;

    //Following Parrents pointes to extract all actions.
    while(node->getParent() != NULL){
        auto it = solution.begin();
        solution.insert(it, node->getAction());
        node = node->getParent();
    }
    return solution;
}