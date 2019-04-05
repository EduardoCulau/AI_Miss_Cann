#include "state.h"

using namespace ai;

void State::setData (const side_t &side, bool boatPosition){
    this->_boatPosition = boatPosition;
    if( boatPosition == RIGHT){
        this->_rightSide = side;
        this->_leftSide = M_PAIR(0,0);
    }else{
        this->_rightSide = M_PAIR(0,0);
        this->_leftSide  = side;
    }
}

void State::setData (elem_t miss, elem_t cann, bool bp){
    this->setData(side_t(miss, cann), bp);
}

void State::move2Right (const side_t &action){
    this->_leftSide  -= action;
    this->_rightSide += action;
    this->_boatPosition = RIGHT;
}

void State::move2Left (const side_t &action){
    this->_rightSide -= action;
    this->_leftSide  += action;
    this->_boatPosition = LEFT;
}

void State::applyAction (const side_t &action){
    if( this->_boatPosition == RIGHT )
        move2Left(action);
    else
        move2Right(action);
}

bool State::operator== (const State& B) const {
    if( this->_rightSide == B._rightSide && this->_leftSide == B._leftSide && this->_boatPosition == B._boatPosition )
        return true;
    else
        return false;
}

namespace ai {

    std::ostream& operator<< (std::ostream &out, const State& state) {
        out <<"< " << state.getLeftSide().first << " , " << state.getLeftSide().second <<" >                   < " 
            << state.getRightSide().first << " , " << state.getRightSide().second << " >"<<std::endl;

        if( state.getBoatPosition() == LEFT ){
            out <<"____________\\____/        ___________"<<std::endl
                <<"           |~\\__/~~~~~~~~~|           ";

        }else{
            out <<"____________        \\____/___________"<<std::endl
                <<"           |~~~~~~~~~\\__/~|           ";
        }
        return out;
    }

}