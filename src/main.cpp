#include <iostream>
#include "includes/LRCSimAllIncludes.hpp"

using namespace LRCSim;

int main()
{
    YoungDiagram yd({5, 4, 3, 3, 3});

    std::cout << yd << std::endl;
}