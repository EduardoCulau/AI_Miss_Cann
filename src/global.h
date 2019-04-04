#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <iostream>

#include <string>
#include <vector>

#define RIGHT false
#define LEFT  true

typedef unsigned int 			  elem_t;
typedef std::pair<elem_t, elem_t> side_t;
typedef std::pair<side_t, side_t> sides_t;

template <typename T, typename U>
std::pair<T,U>& operator+ (const std::pair<T,U> &lhs,const std::pair<T,U> &rhs) {   
    return std::make_pair(lhs.first + rhs.first, lhs.second + rhs.second);
}

template <typename T, typename U>
std::pair<T,U>& operator- (const std::pair<T,U> &lhs,const std::pair<T,U> &rhs) {   
    return std::make_pair(lhs.first - rhs.first, lhs.second - rhs.second);
}

template <typename T, typename U>
std::pair<T,U>& operator+= (std::pair<T,U> &lhs,const std::pair<T,U> &rhs) {
    lhs.first += rhs.first; lhs.second += rhs.second;
    return lhs;   
}

template <typename T, typename U>
std::pair<T,U>& operator-= (std::pair<T,U> &lhs,const std::pair<T,U> &rhs) {   
    lhs.first -= rhs.first; lhs.second -= rhs.second;
    return lhs;   
}

#define M_PAIR(lhs, rhs) std::make_pair(lhs, rhs)

#endif

