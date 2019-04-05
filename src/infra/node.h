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

        Node(const State& state, const elem_t pathCost){
            this->_parent = NULL;
            this->_state  = state;
            this->_pathCost = pathCost;
            this->_action   = M_PAIR(0,0);
        }

        Node(Node* parent, const State& state, const action_t& action, const elem_t pathCost){
            this->_parent = parent;
            this->_state  = state;
            this->_action = action;
            this->_pathCost = pathCost;
        }

        Node(Node* parent, const action_t& action){
            this->_parent = parent;
            this->_action = action;
            this->_state  = Problem::Result(parent->getState(), action);
            this->_pathCost = parent->getPathCost() + Problem::StepCost(parent->getState(), action);
        }

        
        const State& getState()     const{ return _state;    }
        elem_t getPathCost()        const{ return _pathCost; }
        const Node* getParent()     const{ return _parent;   }
        const action_t& getAction() const{ return _action;   }

        static Node* childNode(Node* parent, const action_t& action) {
            Node* cNode = new Node(parent, action);
            return cNode; 
        }

    private:
        Node*    _parent;
        State    _state;
        action_t _action;
        elem_t   _pathCost;

};

}

#endif
