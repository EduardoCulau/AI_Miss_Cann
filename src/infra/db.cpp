#include "db.h"

using namespace ai;

Database *Database::_instance = 0;

void Database::computeValidActions(elem_t miss, elem_t cann, elem_t bc) {
    for( elem_t c = 0; c <= cann; c++ ){
        for( elem_t m = 0; m <= miss; m++){
            if( (m+c) >= 1 && (m+c) <= bc && ((m != 0 && m >= c) || m == 0) ){
                get()->_validActions.emplace_back(m,c);
            }
        }
    }
} 