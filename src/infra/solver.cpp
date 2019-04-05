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
    get()->frontier.push_back(node);
    //Empty explored

    //Loop over the problem space.
    while( true ){
        printf("New While.\n");
        if( get()->frontier.empty() ) return Solution(NULL);
        node = get()->frontier.front(); get()->frontier.pop_front();
        get()->explored.push_back(node);
        std::cout <<" NODO ATUAL "<< node->getPathCost() << std::endl;
        std::cout << node->getState() << std::endl;
        for(auto action : Problem::actions(node->getState())){
            child = Node::childNode(node, action);
            std::cout <<" NODO FILHO "<< child->getPathCost() <<"  < " << child->getAction().first <<" , " << child->getAction().second << " >" << std::endl;
            std::cout << child->getState() << std::endl;
            //Test if the node is not in explored or frontier the
            if( !stateFind(get()->frontier, child->getState()) and !stateFind(get()->explored, child->getState()) ){
                printf("Entrou, filho inedito.\n");
                if( Problem::goalTest(child->getState()) ) return Solution(child);
                get()->frontier.push_back(child);
            }
        }
        printf("End FOR.\n"); 
    }

}


solution_t Solver::Solution (const Node* node){
    solution_t solution;
    if( node == NULL) return solution;
    //Following Parrents pointes to extract all actions.
    while(node->getParent() != NULL){
        auto it = solution.begin();
        solution.insert(it, node->getAction());
        node = node->getParent();
    }
    return solution;
}

bool Solver::stateFind(const data_t& dq, const State& state) {
    auto nodeIt = dq.begin();
    //Findo the state insede the deque.
    for( ; nodeIt != dq.end(); ++nodeIt ){
        if( (*nodeIt)->getState() == state ){
            return true;
        }
    }
    return false;
}