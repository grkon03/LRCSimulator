#include "types.hpp"
#include <string>
#include <iostream>

namespace LRCSim
{
    namespace
    {
        std::string operator*(std::string str, unsigned int times)
        {
            if (times == 0)
                return "";
            else
                return str + (str * (times - 1));
        }
    }

    std::ostream &operator<<(std::ostream &os, const DiagramShape &d)
    {
        if (d.size() == 0)
            return os;

        os << std::string(" ＿") * d[0] << std::endl;

        for (auto l : d)
        {
            os << (std::string("|＿") * l) << "|" << std::endl;
        }

        return os;
    }

    bool isYoung(DiagramShape shape)
    {
        if (shape.size() <= 1)
            return true;

        if (shape[0] < shape[1])
            return false;
        else
            return isYoung(DiagramShape(shape.begin() + 1, shape.end()));
    }

    bool isLatticeWord(RowWord rowWord)
    {
        RowWord revrw = rowWord;
        std::vector<int> counter;

        std::reverse(revrw.begin(), revrw.end());

        // verify yamanouchi word

        int i, _v;

        for (auto v : revrw)
        {
            _v = v - 1;
            if (_v < counter.size())
                ++counter[_v];
            else if (_v == counter.size())
                counter.push_back(0);
            else
                return false;

            for (i = 0; i < counter.size() - 1; ++i)
            {
                if (counter[i] < counter[i + 1])
                    return false;
            }
        }

        return true;
    }
}