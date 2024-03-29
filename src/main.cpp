#include "global.h"
#include "setting.h"
#include "infra/problem.h"
#include "infra/state.h"
#include "infra/node.h"
#include "infra/solver.h"

using namespace ai;

/**
 * Main function that start all the process
 * using an existing infrastructure. 
 *
 * @author      Eduardo Culau
 * @version     1.5
 * @since       1.0
 */
int main(int argc, char **argv)
{   
    /* Read entries */
    if( !Setting::readArgs(argc, argv) )
        return 1;
    
    /* Check entries */
    if( !Setting::parseEntries() ){
        return 1;
    }

    /* Print the parameter */
    std::cout<<"		STARTING		"<<std::endl
             <<"Missionaries  = " << Setting::missionaries() <<std::endl
             <<"Cannibals     = " << Setting::cannibals()    <<std::endl
             <<"Boat Capacity = " << Setting::boatCapacity() <<std::endl << std::endl;

    /* Set the Problem wiht parsed arguments */
    Problem::setInitialState(Setting::missionaries(), Setting::cannibals(), Setting::boatCapacity(), RIGHT);

    /* Print inital and goal state */
    std::cout <<"		INITIAL STATE		" << std::endl
    		  << Problem::getInitialState()   << std::endl << std::endl
    		  <<"		GOAL    STATE		" << std::endl
    		  << Problem::getGoalState() 	  << std::endl << std::endl;

    /* Print the possible actions to solve the problem */
   	std::cout <<"		POSSIBLE ACTIONS    " << std::endl;
   	for( auto act : Problem::getAllValidActions() ){
   		std::cout << act << " | ";
   	}
   	std::cout << std::endl << std::endl <<  std::endl;

    /* Solve the problem */
    solution_t solution;
    solution = Solver::Breadth_First_Search();

    /* Print Solution */
    std::cout << std::endl << std::endl
              <<"-------------------------------------" << std::endl
              <<"               SOLUTION              " << std::endl
              <<"-------------------------------------" << std::endl << std::endl;
    if( solution.empty() ){
      std::cout <<"            NO SOLUTION              "<< std::endl;
    }else{
      for( auto node : solution ){
        Node::printSolutionNode(node);
      }
    }

    return 0;
}


