#ifndef _INFRA_DB_H_
#define _INFRA_DB_H_

#include "state.h"
#include "../global.h"


namespace ai {

class Database
{
    public:
        static Database* get(){
            if ( !_instance ) {
                _instance = new Database;
            }
            return _instance;
        }

        static const State& getInitialState () { return get()->_initialState; }

        static const State& getGoalState () { return get()->_goalState; }

        static const std::vector<side_t>& getAllValidActions () { return get()->_validActions; }

        static void setArguments (elem_t missionaries, elem_t cannibals, elem_t boatCapacity, bool boatPosition){
            get()->_initialState.setData(missionaries, cannibals, boatPosition);
            get()->_goalState.setData   (missionaries, cannibals, !boatPosition);
            get()->computeValidActions(missionaries, cannibals, boatCapacity);
        }

    private:

        void computeValidActions(elem_t miss, elem_t cann, elem_t bc); 

        static Database *_instance;
        Database(){};
        ~Database(){}

        State _initialState;
        State _goalState;

        std::vector<side_t> _validActions;
};

}

#endif

