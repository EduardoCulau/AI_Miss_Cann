#ifndef _INFRA_SOLVER_H_
#define _INFRA_SOLVER_H_

#include "../global.h"
#include "problem.h"
#include "node.h"

namespace ai {

typedef std::deque<Node*>  data_t;
typedef std::vector<const Node*> solution_t;

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

        static bool stateFind (const data_t& dq, const State& state);

        data_t frontier;
        data_t explored;


};

}

#endif

