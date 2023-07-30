#pragma once

#include "SkewDiagram.hpp"
#include "SSTabSim/SSTabSimulatorAllIncludes.hpp"

namespace LRCSim
{
    class LRSkewTableaux : public SkewDiagram
    {
    protected:
        // variables

        /**
         * @brief rowWord: each number is assigned to each (not holed) squares by the following rule.
         * First: a number at some index is assignd to a square at the same index. Second: squares are
         * indexed in increasing order from left to right and from bottom to top.
         *
         */
        RowWord rowWord;

    public:
        // constructors

        LRSkewTableaux(DiagramShape, DiagramShape, RowWord);
        LRSkewTableaux(YoungDiagram, YoungDiagram, RowWord);
        LRSkewTableaux(SkewDiagram, RowWord);
        LRSkewTableaux(SSTabSim::MTab);
        LRSkewTableaux(SSTabSim::TableauxShape);
        LRSkewTableaux(const LRSkewTableaux &);

        // functions

        /**
         * @brief Get the row word
         *
         * @return rowWord
         */
        RowWord getRowWord() const;

        /**
         * @brief Set the row word
         *
         * @param rowWord row word
         */
        void setRowWord(RowWord rowWord);

        /**
         * @brief verify whether this is skew Littlewood-Richardson tableaux.
         *
         * @return whether this is skew Littlewood-Richardson tableaux
         */
        bool isWellNumbered() const;

        // cast

        /**
         * @brief cast to SSTabSim::MTab
         *
         * @return SSTabSim::MTab
         */
        operator SSTabSim::MTab() const;
    };

    // operator

    std::ostream &operator<<(std::ostream &, const LRSkewTableaux &);
}