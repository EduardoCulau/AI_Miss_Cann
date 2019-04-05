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

State Problem::Result ( const State &state, const action_t &action ){
    State newState(state);
    newState.applyAction(action);
    return newState;
}

bool Problem::sideRule (const side_t &side){
    return (side.first <= 0 || side.first >= side.second);
}

bool Problem::testRule (const sides_t &sides){
    return (sideRule(sides.first) && sideRule(sides.second));
}

bool Problem::canApplyAction (const State &state, const action_t &action){
    if( state.getBoatPosition() == RIGHT){
        if( state.getRightSide() >= action ){
            if( testRule( State::move2Left(state, action) ) )
                return true;
        }
    }else{
        if( state.getLeftSide() >= action ){
            if( testRule( State::move2Right(state, action) ) )
                return true;
        }
    }
    return false;
}