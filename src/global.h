#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <iostream>

#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>
#include <cstring>

//#define PRINT_EXEC

namespace ai {

/**
 * Define the boat position
 */
#define RIGHT false
#define LEFT  true

/**
 * Elements (missionaries or cannibals)
 */
typedef unsigned int 			  elem_t;

/**
 * Pair of elements <missionaries, cannibals>
 * Each side has some quantity of miss and cann.
 */
typedef std::pair<elem_t, elem_t> side_t;

/**
 * An action is a movement of some quantity of miss and cann
 */
typedef side_t                    action_t;

/**
 * Two sides <left Side, Right Side> of the river
 */
typedef std::pair<side_t, side_t> sides_t;

/**
 * A bunch of action
 */
typedef std::vector<action_t>     actions_t;

using namespace ai;

/**
 * Template to operator + usend to std::pair. 
 */
template <typename T, typename U>
std::pair<T,U> operator+ (const std::pair<T,U> &lhs, const std::pair<T,U> &rhs) {   
    return std::make_pair(lhs.first + rhs.first, lhs.second + rhs.second);
}

/**
 * Template to operator - usend to std::pair. 
 */
template <typename T, typename U>
std::pair<T,U> operator- (const std::pair<T,U> &lhs, const std::pair<T,U> &rhs) {   
    return std::make_pair(lhs.first - rhs.first, lhs.second - rhs.second);
}

/**
 * Template to operator += usend to std::pair. 
 */
template <typename T, typename U>
std::pair<T,U>& operator+= (std::pair<T,U> &lhs, const std::pair<T,U> &rhs) {
    lhs.first += rhs.first; lhs.second += rhs.second;
    return lhs;   
}

/**
 * Template to operator -= usend to std::pair. 
 */
template <typename T, typename U>
std::pair<T,U>& operator-= (std::pair<T,U> &lhs, const std::pair<T,U> &rhs) {   
    lhs.first -= rhs.first; lhs.second -= rhs.second;
    return lhs;   
}

/**
 * Template to operator << (print) usend to std::pair. 
 */
template <typename T, typename U>
std::ostream& operator<< (std::ostream &out, const std::pair<T,U> &side) {
    out <<"< " << side.first << " , " << side.second << " >";
    return out;
}

/**
 * Make a pair. 
 */
#define M_PAIR(lhs, rhs) std::make_pair(lhs, rhs)

}

#endif

