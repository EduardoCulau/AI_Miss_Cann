#ifndef _INFRA_STATE_H_
#define _INFRA_STATE_H_

#include "../global.h"

namespace ai {

/**
 * State is the base class of the problem. 
 * It define a state of the problem like:
 *      ° Number of elements in each side of the river.
 *      ° Position of the boat (bank of the river).
 *      ° Define methods to move element from each side.
 *      ° Define a print method to show the state.
 *
 * @author      Eduardo Culau
 * @version     1.5
 * @since       1.1
 */
class State
{
public:

    /**
     * Simplest constructor
     *
     * @return      an empty State.
     */
    State (){
        this->_rightSide = M_PAIR(0,0);
        this->_leftSide  = M_PAIR(0,0);
    }

    /**
     * Creates a State, setting the element to a specific side defined by the boat position
     *
     * @param  side         pair of elements <missionaries, cannibals>
     * @param  boatPosition position of the boat (which side is it)
     * @return State        an object of class State
     */
    State(const side_t &side, bool boatPosition){
        this->setData(side, boatPosition);
    }

    /**
     * Creates a State, setting the element to a specific side defined by the boat position
     *
     * @param  miss         number of missionaries
     * @param  elem_t       number of cannibals
     * @param  boatPosition position of the boat (which side is it)
     * @return State        an object of class State
     */
    State(elem_t miss, elem_t cann, bool boatPosition){
        State(side_t(miss, cann), boatPosition);
    }

    /**
     * Creates a State, copying an existing one
     *
     * @param  origin an existing State
     * @return State  an object of class State
     */
    State(const State &origin){
        sides_t sides       = origin.getSides();
        this->_leftSide     = sides.first;
        this->_rightSide    = sides.second;
        this->_boatPosition = origin.getBoatPosition();
    }

    /**
     * Set the side and a boat positon to the state.
     *
     * @param  side         pair of elements <missionaries, cannibals>
     * @param  boatPosition position of the boat (which side is it)
     */    
    void setData (const side_t &side, bool boatPosition);

    /**
     * Set the number of missionaries, cannibals and
     * the boat positon to the state.
     *
     * @param  miss         number of missionaries
     * @param  cann         number of cannibals
     * @param  boatPosition position of the boat (which side is it)
     */   
    void setData (elem_t miss, elem_t cann, bool boatPosition);

    /**
     * Move elements to right side of the river.
     *
     * @param  action elements to be moved
     */ 
    void    move2Right  (const action_t &action);

    /**
     * Move elements to left side of the river.
     *
     * @param  action elements to be moved
     */ 
    void    move2Left   (const action_t &action);

    /**
     * Move elements to the opposite side of the river
     * based in boat position.
     *
     * @param  action        elements to be moved
     * @see    move2Right()
     * @see    move2Left()
     */ 
    void    applyAction (const action_t &action);

    /**
     * Simulate a movement to the right and return the solution of this movement.
     *
     * @param  state   state to be simulated the aciotn
     * @param  action  elements to be moved
     * @return sides_t two sides <left Side, Right Side> of the river
     */    
    static sides_t move2Right  (const State &state, const action_t &action);

    /**
     * Simulate a movement to the left and return the solution of this movement.
     *
     * @param  state   state to be simulated the aciotn
     * @param  action  elements to be moved
     * @return sides_t two sides <left Side, Right Side> of the river
     */  
    static sides_t move2Left   (const State &state, const action_t &action);

    /**
     * Operator ==. Compare if a State is equal to ohter one.
     *
     * @param  otherState   state to be compared to the implicit one
     * @return              true if the state is equal else false
     */  
    bool operator== (const State& otherState) const;

    /**
     * Get the right side of the state.
     *
     * @return side_t pair of elements <missionaries, cannibals> from the right side.
     */
    inline const side_t&   getRightSide() const { return _rightSide; }

    /**
     * Get the left side of the state.
     *
     * @return side_t pair of elements <missionaries, cannibals> from the left side.
     */
    inline const side_t&   getLeftSide()  const { return _leftSide;  }

    /**
     * Get both sides of the river (State).
     *
     * @return sides_t pair of elements <leftSide, rightSide> of the river
     */
    inline sides_t  getSides() const { return sides_t(_leftSide, _rightSide); };

    /**
     * Get the boat position
     *
     * @return bool false (RIGHT) or true (LEFT)
     */
    inline bool     getBoatPosition() const { return _boatPosition; };

    /**
     * Operator <<. So it's possible to print the state just put it on the std::cout method.
     *
     * @param  out           existing std::ostream
     * @param  state         state to be printed
     * @return std::ostream& std::ostream whith the State data
     * @see    std::ostream
     */  
    friend std::ostream& operator<< (std::ostream &out, const State& state);

private:
    /**
     * Pair of elements <missionaries, cannibals> from the right side of the river.
     */  
    side_t  _rightSide;      //<Missionari, Cannibal> on right side of the river

    /**
     * Pair of elements <missionaries, cannibals> from the left side of the river.
     */ 
    side_t  _leftSide;      //<Missionari, Cannibal> on right side of the river

    /**
     * Position of the boat (right or left side)
     */ 
    bool    _boatPosition; //Position of the boat,  0=right, 1=left
};

}

#endif

