#include "problem.h"

using namespace ai;

Problem *Problem::_instance = 0;


void Problem::setArguments (elem_t missionaries, elem_t cannibals, elem_t boatCapacity, bool boatPosition){
    get()->_initialState.setData(missionaries, cannibals, boatPosition);
    get()->_goalState.setData   (missionaries, cannibals, !boatPosition);
    get()->computeValidActions(missionaries, cannibals, boatCapacity);
}

void Problem::computeValidActions(elem_t miss, elem_t cann, elem_t bc) {
    for( elem_t c = 0; c <= cann; c++ ){
        for( elem_t m = 0; m <= miss; m++){
            if( (m+c) >= 1 && (m+c) <= bc && ((m != 0 && m >= c) || m == 0) ){
                get()->_validActions.emplace_back(m,c);
            }
        }
    }
}

State Problem::Result ( const State &state, const side_t &action ){
    State newState(state);
    newState.applyAction(action);
    return newState;
}

bool Problem::canApplyAction (const State &state, side_t &action){
    if( state.getBoatPosition() == RIGHT){
        if( state.getRightSide() >= action )
            return true;
    }else{
        if( state.getLeftSide() >= action )
            return true;
    }
    return false;
}