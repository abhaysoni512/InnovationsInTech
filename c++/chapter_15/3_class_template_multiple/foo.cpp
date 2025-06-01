#include "pair.h"
#include <iostream>

void foo(){
    pair<int> p{1, 2};
    std::cout << get_max(p) << std::endl;
}