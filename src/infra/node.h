#ifndef _INFRA_NODE_H_
#define _INFRA_NODE_H_

#include "global.h"
#include "state.h"

namespace ai {

class Node
{
    public:
        Node();
        ~Node();

        Node& childNode(const Node& parent, const side_t& action){
            
        }

    private:
        State  _state;
        Node&  _parent;
        side_t _action;
        elem_t _pathCost;

};

}

#endif
