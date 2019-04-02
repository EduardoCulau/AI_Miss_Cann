#ifndef _STATE_H_
#define _STATE_H_

namespace ai {

#define RIGHT 0
#define LEFT  1

typedef std::pair<unsigned, unsigned> side_t;
typedef std::pair<side_t, side_t>     sides_t;

template <typename T, typename U>
std::pair<T,U>& operator+ (const std::pair<T,U> &l,const std::pair<T,U> &r) {   
    return std::make_pair(l.first + r.first, l.second + r.second);
}

std::pair<T,U>& operator- (const std::pair<T,U> &l,const std::pair<T,U> &r) {   
    return std::make_pair(l.first - r.first, l.second - r.second);
}

std::pair<T,U>& operator+= (const std::pair<T,U> &r) {
    this.first += r.first; this.second += r.second;
    return *this;   
}

std::pair<T,U>& operator-= (const std::pair<T,U> &r) {   
    this.first -= r.first; this.second -= r.second;
    return *this;   
}

class State
{
    public:
        State(const side_t &side, bool boatPosition){
            this._boatPosition = boatPosition;
            if( boatPosition == RIGHT){
                this._rightSide = side;
                this._leftSide(0,0);
            }else{
                this._rightSide(0,0);
                this._leftSide  = side;
            }
        }

        State(int miss, int cann, bool bp){
            State(side_t(miss, cann), bp);
        }

        //Create a new state, applying a action. Don't check if the action is applicable.
        State(const State &origin, side_t action){
            sides_t sides      = origin.getSides();
            this._leftSide     = sides.first;
            this._rightSide    = sides.second;
            this._boatPosition =  origin.getBoatPosition();
            this.applyAction(action);
        }

        void move2Right (side_t action){
            this._leftSide  -= action;
            this._rightSide += action;
            this._boatPosition = RIGHT;
        }

        void move2Left (side_t action){
            this._rightSide -= action;
            this._leftSide  += action;
            this._boatPosition = LEFT;
        }

        void applyAction (side_t action){
            if( this._boatPosition == RIGHT )
                move2Left(action);
            else
                move2Right(action);
        }

        bool canApplyAction (side_t action){
            if( this._boatPosition == RIGHT){
                if( this._rightSide >= action )
                    return true;
            }else{
                if( this._leftSide >= action )
                    return true;
            }
            return false;
        }

        bool operator== (const State& A, const State& B){
            if( A._rightSide == B._rightSide && A._leftSide == B._leftSide && A._boatPosition == B._boatPosition )
                return true;
            else
                return false;
        }

        inline sides_t& getSides() { return sides_t(_leftSide, _rightSide) };
        inline bool     getBoatPosition() { return _boatPosition };

    private:
        side_t  _rightSide;      //<Missionari, Cannibal> on right side of the river
        side_t  _leftSide;      //<Missionari, Cannibal> on right side of the river
        bool    _boatPosition; //Position of the boat,  0=right, 1=left
};

}

#endif

