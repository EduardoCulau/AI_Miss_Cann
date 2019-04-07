#ifndef _INFRA_DB_H_
#define _INFRA_DB_H_

#include "../global.h"
#include "state.h"
#include "node.h"

namespace ai {

/**
 * Problem is a Singleton Class that define the problem.
 * It has argument and method used to solve the problem:
 *      ° Initial State
 *      ° Goal State (always the opposite of initial state)
 *      ° Valid action (operators)
 *      ° Rules checkers
 *
 * @author      Eduardo Culau
 * @version     1.5
 * @since       1.2
 */
class Problem
{
public:
    /**
     * Return the current instance or create one if it don't exist.
     *
     * @return      Setting pointer
     */
    static Problem* get(){
        if ( !_instance ) {
            _instance = new Problem;
        }
        return _instance;
    }

    /**
     * Get the initial state
     *
     * @return State the initial State
     * @see    State
     */
    static const State& getInitialState () { return get()->_initialState; }

    /**
     * Get the goal state
     *
     * @return State the goal State
     * @see    State
     */
    static const State& getGoalState () { return get()->_goalState; }

    /**
     * Get all valid actions (possible actions)
     *
     * @return actions_t a bunch of valid action
     */
    static const actions_t& getAllValidActions () { return get()->_validActions; }

    /**
     * Set the inital state of the problem
     *
     * @param  missionaries number of missionaries
     * @param  cannibals    number of cannibals
     * @param  boatCapacity boat Capacity
     * @param  boatPosition position of the boat (right or left side)
     */
    static void setInitialState (elem_t missionaries, elem_t cannibals, elem_t boatCapacity, bool boatPosition);

    /**
     * Create a new state, applying an action. 
     * Don't check if the action is applicable.
     *
     * @param  state  existing state
     * @param  action action to be applied
     * @return State  new state
     * @see    State
     */
    static State Result ( const State &state, const action_t &action );

    /**
     * Compute the step cost of an action over a State. 
     * Currently is always 1.
     *
     * @param  state  existing state
     * @param  action action to be applied
     * @return elem_t the cost of aply this action.
     */
    static const elem_t StepCost ( const State &state, const action_t &action ) { return 1; }

    /**
     * Test if a state is the goal state. 
     *
     * @param  state  existing state
     * @return bool   true if the goal state else false
     */
    static bool goalTest (const State &state) { return (state == get()->_goalState); }

    /**
     * Test if a side is correct.
     * The number of missionaries in a side must be greater or equal the cannibals.
     *
     * @param  side the side to be tested
     * @return bool true if side is ok else false
     */
    inline static bool sideRule (const side_t &side);

    /**
     * Test if a both sides is correct.
     * The number of missionaries in a side must be greater or equal the cannibals.
     *
     * @param  sides both (left and right) sides
     * @return bool  true if both sides are ok else false
     */    
    inline static bool testRule (const sides_t &sides);

    /**
     * Test if is possible to apply and action to some state.
     * The number of missionaries in a side must be greater or equal the cannibals.
     *
     * @param  state  existing state to be tested
     * @param  action action to be applied
     * @return bool   true if is possible to apply the action else false
     */    
    static bool canApplyAction (const State &state, const action_t &action);

    /**
     * Check all valid action on a state and return just the applicable ones.
     *
     * @param  state     existing state to be tested
     * @return actions_t all applicable actions
     */  
    static actions_t actions (const State &state);

private:

    /**
     * Compute all valid actions based on some parameters.
     *
     * @param  miss number of missionaries
     * @param  cann number of cannibals
     * @param  bc   boat Capacity
     */    
    void computeValidActions(elem_t miss, elem_t cann, elem_t bc);

    /**
     * The single instance of the class.
     */    
    static Problem *_instance;

    /**
     * Private Constructor 
     */    
    Problem(){}
    
    /**
     * Private Destructor
     */
    ~Problem(){}

    /**
     * The initial state of the problem
     */      
    State _initialState;

    /**
     * The goal state of the problem
     */      
    State _goalState;

    /**
     * All valid actions of the problem
     */  
    actions_t _validActions;
};

}

#endif

