#ifndef _DB_H_
#define _DB_H_

#include "state.h"


namespace ispd19 {

class Database
{
    public:
        static Database* get(){
            if ( !_instance ) {
                _instance = new Database;
            }
            return _instance;
        }

        inline State& getInitialState () { return get()->_initialState; }

        inline State& getGoalState () { return get()->_goalState; }

        std::vector<side_t>& getAllValidActions () { return get()->_validActions; }

    private:

        void computeValidActions(unsigned miss, unsigned cann, unsigned bc) {
            for( unsigned c = 0; c <= cann; c++ ){
                for( unsigned m = 0; m <= miss; c++){
                    if( (m+c) >= 1 && (m+c) <= bc && (m /= 0 && m >= c || m == 0) )
                        get()->_validActions.emplace(m,c);
                }
            }
        } 

        static Database *_instance;
        Database(unsigned missionaries, unsigned cannibals, unsigned boatCapacity, bool boatPosition){
            get()->_initialState(missionaries, cannibals, boatPosition);
            get()->_goalState   (missionaries, cannibals, !boatPosition);
            get()->computeValidActions(missionaries, cannibals, boatCapacity);
        }
        ~Database(){}

        State _initialState;
        State _goalState;

        std::vector<side_t> _validActions;
};

}

#endif

