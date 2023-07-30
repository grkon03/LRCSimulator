#include <iostream>
#include "includes/LRCSimAllIncludes.hpp"
#include <map>

using namespace LRCSim;

int main()
{
    // sample program

    const int N = 10;
    int i, j;
    int all = 0;

    std::vector<YoungDiagram> lists[N];
    LRCCalculator tempcal;
    std::map<int, int> counter;

    for (i = 0; i < N; ++i)
    {
        lists[i] = YoungDiagram::enumPartitions(i);
    }

    for (i = 1; i < N; ++i)
    {
        for (j = 1; j < i; ++j)
        {
            for (auto con : lists[i])
            {
                for (auto hol : lists[j])
                {
                    for (auto wei : lists[i - j])
                    {
                        try
                        {
                            tempcal = LRCCalculator(con, hol, wei);
                        }
                        catch (const char *err)
                        {
                            continue;
                        }
                        ++all;
                        if (tempcal.getCoefficient() == 0)
                            continue;
                        ++counter[tempcal.getCoefficient()];
                        // std::cout << "Container: " << std::endl;
                        // std::cout << con << std::endl;
                        // std::cout << "Hole: " << std::endl;
                        // std::cout << hol << std::endl;
                        // std::cout << "Weight: " << std::endl;
                        // std::cout << wei << std::endl;
                        // std::cout << std::endl;
                        // std::cout << "coefficient: " << tempcal.getCoefficient() << std::endl;
                        // std::cout << std::endl;
                        // std::cout << "tableauxes: " << std::endl;
                        // for (auto tab : tempcal.getAbleTableauxes())
                        // {
                        //     std::cout << tab << std::endl;
                        // }
                        // std::cout << std::endl;
                        // std::cout << "****************************" << std::endl;
                        // std::cout << std::endl;
                    }
                }
            }
        }
    }

    std::cout << "N: " << N << std::endl;
    std::cout << "count: " << std::endl;
    std::cout << "  all: " << all << std::endl;

    for (auto [k, v] : counter)
    {
        std::cout << "  " << k << ": " << v << std::endl;
    }
}