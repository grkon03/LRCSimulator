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

    LRCCalculator lrcc(
        {8, 5, 3},
        {5, 4},
        {4, 2, 1});

    std::cout << lrcc.getContainer() << std::endl;
    std::cout << lrcc.getHole() << std::endl;
    std::cout << lrcc.getWeight() << std::endl;

    std::cout << std::endl
              << "Littlewood-Robbinson Coefficient is " << lrcc.getCoefficient()
              << " in such the skew Littlewood-Robbinson Tableaux" << std::endl
              << std::endl;

    std::cout << "All the Tableauxes: " << std::endl
              << std::endl;

    for (auto s : lrcc.getAbleTableauxes())
    {
        std::cout << s << std::endl;
    }
}