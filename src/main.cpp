#include <iostream>
#include "vector.h"
#include <cassert>
#include <cstdio>
#include <stdexcept>
#include <string>

int main(){
    CustomVector<int> v1;
    v1.pushBack(1);
    std::cout << v1.size() << std::endl;
    v1.pushBack(1);
}
