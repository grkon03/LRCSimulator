#pragma once

#include <vector>
#include <ostream>

namespace LRCSim
{
    using DiagramShape = std::vector<int>;
    using RowWord = std::vector<int>;

    std::ostream &operator<<(std::ostream &os, const DiagramShape &d);

    /**
     * @brief verify whether this is shaped as Young diagram
     *
     * @param shape the target of verification
     * @return whether this is shaped as Young diagram
     */
    bool isYoung(DiagramShape shape);

    /**
     * @brief verify whether this is a lattice word
     *
     * @param rowWord
     * @return verify whether this is a lattice word
     */
    bool isLatticeWord(RowWord rowWord);
}