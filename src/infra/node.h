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

        Node(const State& state, const elem_t pathCost);

        Node(Node* parent, const State& state, const action_t& action, const elem_t pathCost);

        Node(Node* parent, const action_t& action);

        ~Node() {}

        
        const State& getState()     const{ return _state;    }
        elem_t getPathCost()        const{ return _pathCost; }
        const Node* getParent()     const{ return _parent;   }
        const action_t& getAction() const{ return _action;   }

        static Node* childNode(Node* parent, const action_t& action);

        static void printCurrentNode      (const Node* node);
        static void printChieldNode_Start ();
        static void printChieldNode       (const Node* node);
        static void printChieldNode_End   ();
        static void printSolutionNode     (const Node* node);

    private:
        Node*    _parent;
        State    _state;
        action_t _action;
        elem_t   _pathCost;

};

}

#endif
