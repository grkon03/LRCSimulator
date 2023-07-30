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

    LRSkewTableaux lrst(sd, {3, 2, 1, 1});

    std::cout << lrst << std::endl;

    LRSkewTableaux lrst2(SSTabSim::TableauxShape(
        {{0, 0, 0, 1},
         {0, 2, 1},
         {3}}));

    std::cout << lrst2 << std::endl;
}