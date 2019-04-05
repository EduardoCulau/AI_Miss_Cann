#ifndef _INFRA_SOLVER_H_
#define _INFRA_SOLVER_H_

#include "../global.h"
#include "problem.h"
#include "node.h"

namespace ai {

class Solver
{
    public:
        static Solver* get(){
            if ( !_instance ) {
                _instance = new Solver;
            }
            return _instance;
        }        

        static solution_t Breadth_First_Search ();
        static solution_t Solution (const Node* node);


    private:
        static Solver *_instance;
        Solver(){}
        ~Solver(){}

        std::queue<Node*> frontier;
        std::queue<Node*> allNodes;
        std::queue<Node*> explored;


};

}

#endif

