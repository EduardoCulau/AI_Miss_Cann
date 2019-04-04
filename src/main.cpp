#include "global.h"
#include "setting.h"
#include "infra/db.h"
#include "infra/state.h"

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

    //Set the database wiht parsed arguments
    Database::setArguments(Setting::missionaries(), Setting::cannibals(), Setting::boatCapacity(), RIGHT);


    std::cout <<"		INITIAL STATE		" << std::endl
    		  <<Database::getInitialState()   << std::endl << std::endl
    		  <<"		GOAL    STATE		" << std::endl
    		  <<Database::getGoalState() 	  << std::endl << std::endl;


   	std::cout <<"		POSSIBLE ACTIONS    " << std::endl;
   	for( auto act : Database::getAllValidActions() ){
   		std::cout <<"< " << act.first <<" , " << act.second << " >" << " | ";
   	}
   	std::cout << std::endl << std::endl;

    return 0;
}


