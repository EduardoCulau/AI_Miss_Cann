#include "global.h"
#include "setting.h"
#include "infra/problem.h"
#include "infra/state.h"
#include "infra/solver.h"

using namespace ai;

int main(int argc, char **argv)
{   
    //Read entries
    if( !Setting::readArgs(argc, argv) )
        return 1;
    
    //Check entries
    if( !Setting::parseEntries() ){
        return 1;
    }

    std::cout<<"		STARTING		"<<std::endl
             <<"Missionaries  = " << Setting::missionaries() <<std::endl
             <<"Cannibals     = " << Setting::cannibals()    <<std::endl
             <<"Boat Capacity = " << Setting::boatCapacity() <<std::endl << std::endl;

    //Set the Problem wiht parsed arguments
    Problem::setArguments(Setting::missionaries(), Setting::cannibals(), Setting::boatCapacity(), RIGHT);


    std::cout <<"		INITIAL STATE		" << std::endl
    		  <<Problem::getInitialState()   << std::endl << std::endl
    		  <<"		GOAL    STATE		" << std::endl
    		  <<Problem::getGoalState() 	  << std::endl << std::endl;


   	std::cout <<"		POSSIBLE ACTIONS    " << std::endl;
   	for( auto act : Problem::getAllValidActions() ){
   		std::cout <<"< " << act.first <<" , " << act.second << " >" << " | ";
   	}
   	std::cout << std::endl << std::endl <<  std::endl;

    //Solver
    solution_t solution;

    solution = Solver::Breadth_First_Search();

    //Print Solution.
    std::cout << "   SOLUTION     " << std::endl;
    for( auto action : solution ){
      std::cout <<"< " << action.first <<" , " << action.second << " >" <<std::endl;
    }


    return 0;
}


