#ifndef _INFRA_SOLVER_H_
#define _INFRA_SOLVER_H_

#include "../global.h"
#include "problem.h"
#include "node.h"

namespace ai {

/**
 * Deque to store the Nodes pointers.
 */
typedef std::deque<Node*>  store_t;

/**
 * Vector of Node pointers which are the solution.
 */
typedef std::vector<const Node*> solution_t;


/**
 * Solver is a Singleton Class that defines the solver of the problem.
 * It has argument and method like:
 *      ° Frontier
 *      ° Explored
 *      ° Breadth_First_Search
 *
 * @author      Eduardo Culau
 * @version     1.5
 * @since       1.4
 */
class Solver
{
public:

    /**
     * Return the current instance or create one if it don't exist.
     *
     * @return Solver* Setting pointer
     */
    static Solver* get(){
        if ( !_instance ) {
            _instance = new Solver;
        }
        return _instance;
    }        

    /**
     * Applies the Breadth First Search on the problem and solve it.
     *
     * @return solution_t solution of the problem
     */
    static solution_t Breadth_First_Search ();

    /**
     * Travel back to the origin to get all solution nodes.
     *
     * @param  node       pointer of the last node
     * @return solution_t solution of the problem
     */
    static solution_t Solution (const Node* node);

private:

    /**
     * The single instance of the class.
     */   
    static Solver *_instance;

    /**
     * Private Constructor 
     */   
    Solver(){}

    /**
     * Private Destructor
     */
    ~Solver(){}

    /**
     * Applies the Breadth First Search on the problem and solve it.
     *
     * @param  node       pointer of the last node
     * @return solution_t solution of the problem
     */
    static bool stateFind (const store_t& dq, const State& state);

    /**
     * Deque to store the Nodes* in the frontier. Used to solve the problem.
     */  
    store_t frontier;

    /**
     * Deque to store the Nodes* that was explored. Used to solve the problem.
     */  
    store_t explored;
};

}

#endif

