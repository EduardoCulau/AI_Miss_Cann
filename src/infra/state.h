#ifndef _INFRA_STATE_H_
#define _INFRA_STATE_H_

#include "../global.h"

namespace ai {

class State
{
    public:
        State (){
            this->_rightSide = M_PAIR(0,0);
            this->_leftSide  = M_PAIR(0,0);
        }

        State(const side_t &side, bool boatPosition){
            this->setData(side, boatPosition);
        }

        State(elem_t miss, elem_t cann, bool bp){
            State(side_t(miss, cann), bp);
        }

        //Create a copy o the origin statre.
        State(const State &origin){
            sides_t sides       = origin.getSides();
            this->_leftSide     = sides.first;
            this->_rightSide    = sides.second;
            this->_boatPosition = origin.getBoatPosition();
        }

        void setData (const side_t &side, bool boatPosition);
        void setData (elem_t miss, elem_t cann, bool bp);


        void    move2Right  (const action_t &action);
        void    move2Left   (const action_t &action);
        void    applyAction (const action_t &action);

        static sides_t move2Right  (const State &state, const action_t &action);
        static sides_t move2Left   (const State &state, const action_t &action);

        bool operator== (const State& B) const;

        inline const side_t&   getRightSide() const { return _rightSide; }
        inline const side_t&   getLeftSide()  const { return _leftSide;  }
        inline sides_t  getSides() const { return sides_t(_leftSide, _rightSide); };
        inline bool     getBoatPosition() const { return _boatPosition; };

        friend std::ostream& operator<< (std::ostream &out, const State& state);

    private:
        side_t  _rightSide;      //<Missionari, Cannibal> on right side of the river
        side_t  _leftSide;      //<Missionari, Cannibal> on right side of the river
        bool    _boatPosition; //Position of the boat,  0=right, 1=left
};

}

#endif

