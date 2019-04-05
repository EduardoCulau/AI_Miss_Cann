#ifndef _INFRA_DB_H_
#define _INFRA_DB_H_

#include "state.h"
#include "../global.h"


namespace ai {

class Problem
{
    public:
        static Problem* get(){
            if ( !_instance ) {
                _instance = new Problem;
            }
            return _instance;
        }

        static const State& getInitialState () { return get()->_initialState; }

        static const State& getGoalState () { return get()->_goalState; }

        static const std::vector<side_t>& getAllValidActions () { return get()->_validActions; }

        static void setArguments (elem_t missionaries, elem_t cannibals, elem_t boatCapacity, bool boatPosition);

        //Create a new state, applying a action. Don't check if the action is applicable.
        static State Result ( const State &state, const side_t &action );

        //Add one level.
        static const elem_t StepCost ( const State &state, const side_t &action ) { return 1; }

        static bool canApplyAction (const State &state, side_t &action);

    private:

        void computeValidActions(elem_t miss, elem_t cann, elem_t bc); 

        static Problem *_instance;
        Problem(){}
        ~Problem(){}

        State _initialState;
        State _goalState;

        std::vector<side_t> _validActions;
};

}

#endif

