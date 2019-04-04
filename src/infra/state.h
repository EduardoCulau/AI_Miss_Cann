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

        //Create a new state, applying a action. Don't check if the action is applicable.
        State(const State &origin, side_t action){
            sides_t sides       = origin.getSides();
            this->_leftSide     = sides.first;
            this->_rightSide    = sides.second;
            this->_boatPosition =  origin.getBoatPosition();
            this->applyAction(action);
        }

        void setData (const side_t &side, bool boatPosition){
            this->_boatPosition = boatPosition;
            if( boatPosition == RIGHT){
                this->_rightSide = side;
                this->_leftSide = M_PAIR(0,0);
            }else{
                this->_rightSide = M_PAIR(0,0);
                this->_leftSide  = side;
            }
        }

        void setData (elem_t miss, elem_t cann, bool bp){
            this->setData(side_t(miss, cann), bp);
        }


        void move2Right (side_t action){
            this->_leftSide  -= action;
            this->_rightSide += action;
            this->_boatPosition = RIGHT;
        }

        void move2Left (side_t action){
            this->_rightSide -= action;
            this->_leftSide  += action;
            this->_boatPosition = LEFT;
        }

        void applyAction (side_t action){
            if( this->_boatPosition == RIGHT )
                move2Left(action);
            else
                move2Right(action);
        }

        bool canApplyAction (side_t action){
            if( this->_boatPosition == RIGHT){
                if( this->_rightSide >= action )
                    return true;
            }else{
                if( this->_leftSide >= action )
                    return true;
            }
            return false;
        }

        bool operator== (const State& B) const {
            if( this->_rightSide == B._rightSide && this->_leftSide == B._leftSide && this->_boatPosition == B._boatPosition )
                return true;
            else
                return false;
        }

        inline sides_t  getSides() const { return sides_t(_leftSide, _rightSide); };
        inline bool     getBoatPosition() const { return _boatPosition; };


        friend std::ostream& operator<< (std::ostream &out, const State& state) {
            out <<"< " << state._leftSide.first << " , " << state._leftSide.second <<" >                   < " << state._rightSide.first << " , " << state._rightSide.second << " >"<<std::endl;

            if( state._boatPosition == LEFT ){
                out <<"___________\\______/        ___________"<<std::endl
                    <<"           |\\    /        |           "<<std::endl
                    <<"           |~\\__/~~~~~~~~~|           ";

            }else{
                out <<"___________        \\______/___________"<<std::endl
                    <<"           |        \\    /|           "<<std::endl
                    <<"           |~~~~~~~~~\\__/~|           ";
            }
            return out;
        }

    private:
        side_t  _rightSide;      //<Missionari, Cannibal> on right side of the river
        side_t  _leftSide;      //<Missionari, Cannibal> on right side of the river
        bool    _boatPosition; //Position of the boat,  0=right, 1=left
};

}

#endif

