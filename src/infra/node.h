#ifndef _INFRA_NODE_H_
#define _INFRA_NODE_H_

#include "global.h"
#include "problem.h"
#include "state.h"

namespace ai {

class Node
{
    public:
        Node() {
            this->_parent   = NULL;
            this->_pathCost = 0;
            this->_action   = M_PAIR(0,0);
        }

        Node( State& state, const elem_t pathCost){
            this->_parent = NULL;
            this->_state  = state;
            this->_pathCost = pathCost;
            this->_action   = M_PAIR(0,0);
        }

        Node( Node* parent, const State& state, const side_t& action, const elem_t pathCost){
            this->_parent = parent;
            this->_state  = state;
            this->_action = action;
            this->_pathCost = pathCost;
        }

        Node( Node* parent, const side_t& action){
            this->_parent = parent;
            this->_action = action;
            this->_state  = Problem::Result(parent->getState(), action);
            this->_pathCost = parent->getPathCost() + Problem::StepCost(parent->getState(), action);
        }

        ~Node();

        
        const State& getState() const{ return _state;    }
        elem_t getPathCost()    const{ return _pathCost; }

        Node* childNode(Node* parent, const side_t& action) {
            Node* cNode = new Node(parent, action);
            return cNode; 
        }

    private:
        Node*  _parent;
        State  _state;
        side_t _action;
        elem_t _pathCost;

};

}

#endif
