#ifndef _INFRA_NODE_H_
#define _INFRA_NODE_H_

#include "global.h"
#include "problem.h"
#include "state.h"

namespace ai {

/**
 * Node is a Class that defines a node to help to solve the problem.
 * It has argument and method like:
 *      ° State
 *      ° Path Cost
 *      ° Applied Action
 *      ° Create a child node
 *
 * @author      Eduardo Culau
 * @version     1.5
 * @since       1.3
 */
class Node
{
public:

    /**
     * Simplest constructor
     *
     * @return Node an object of class Node
     */
    Node() {
        this->_parent   = NULL;
        this->_pathCost = 0;
        this->_action   = M_PAIR(0,0);
    }

    /**
     * Creates a Node, setting the state and the path Cost.
     *
     * @param  state    state of the node
     * @param  pathCost cost of the node
     * @return Node     an object of class Node
     */
    Node(const State& state, const elem_t pathCost);

    /**
     * Creates a Node, setting the parent, state, action and the path Cost.
     *
     * @param  parent   parent node
     * @param  state    state of the node
     * @param  action   action applied 
     * @param  pathCost cost of the node
     * @return Node     an object of class Node
     */
    Node(Node* parent, const State& state, const action_t& action, const elem_t pathCost);

    /**
     * Creates a Node, setting the parent and action.
     *
     * @param  parent   parent node
     * @param  action   action applied 
     * @return Node     an object of class Node
     */
    Node(Node* parent, const action_t& action);

    /**
     * Destructor
     */
    ~Node() {}

    /**
     * Get the state of the node.
     *
     * @return State state of the node
     * @see    State
     */
    const State& getState()     const{ return _state;    }

    /**
     * Get the path cost of the node.
     *
     * @return elem_t pathCost of the node
     */
    elem_t getPathCost()        const{ return _pathCost; }

    /**
     * Get the parent node of the node.
     *
     * @return Node* pointer to the parent node.
     */
    const Node* getParent()     const{ return _parent;   }

    /**
     * Get the action of the node
     *
     * @return action_t action of the node
     */
    const action_t& getAction() const{ return _action;   }

    /**
     * Create a new child node from a parent one, applying an action.
     *
     * @param  parent the parent node
     * @param  action taken action
     * @return Node*  pointer to the child node
     */  
    static Node* childNode(Node* parent, const action_t& action);

    /**
     * Static function to print a node as the current one.
     *
     * @param node pointer to a node
     */  
    static void printCurrentNode      (const Node* node);

    /**
     * Static function to start the printing of the child nodes.
     */  
    static void printChieldNode_Start ();

    /**
     * Static function to print a node as the child one.
     *
     * @param node pointer to a node
     */      
    static void printChieldNode       (const Node* node);

    /**
     * Static function to end the printing of the child nodes.
     */  
    static void printChieldNode_End   ();

    /**
     * Static function to print a node as the solution one.
     *
     * @param node pointer to a node
     */  
    static void printSolutionNode     (const Node* node);

private:
    /**
     * Pointer to the parent Node
     */  
    Node*    _parent;

    /**
     * State of the node
     */  
    State    _state;

    /**
     * Action taken to generate this state
     */  
    action_t _action;

    /**
     * Cost of the Node
     */  
    elem_t   _pathCost;

};

}

#endif
