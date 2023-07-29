#include <iostream>
#include "includes/LRCSimAllIncludes.hpp"

using namespace LRCSim;

int main()
{
    // sample program

    YoungDiagram yd({5, 4, 3, 3, 3});

    std::cout << yd << std::endl;

    SkewDiagram sd({4, 3, 1}, {3, 1});

    std::cout << sd << std::endl;
}