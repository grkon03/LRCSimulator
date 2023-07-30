#pragma once

#include "LRSkewTableaux.hpp"

namespace LRCSim
{
    class LRCCalculator : public SkewDiagram
    {
    protected:
        // variables

        /**
         * @brief the weight of skew Littlewood-Richardson tableaux
         *
         */
        YoungDiagram weight;

        /**
         * @brief able skew Littlewood-Robbinson tableaux
         *
         */
        std::vector<LRSkewTableaux> ableTableauxes;

        /**
         * @brief Littlewood-Robbinson Coefficient
         *
         */
        int coefficient;

    public:
        // constructors

        LRCCalculator(DiagramShape, DiagramShape, DiagramShape);
        LRCCalculator(YoungDiagram, YoungDiagram, YoungDiagram);
        LRCCalculator(SkewDiagram, DiagramShape);
        LRCCalculator(SkewDiagram, YoungDiagram);
        LRCCalculator(const LRCCalculator &);

        // functions

        /**
         * @brief Get the weight
         *
         * @return weight
         */
        YoungDiagram getWeight() const;

        /**
         * @brief Get the able skew Littlewood-Robbinson tableauxes
         *
         * @return the list of able skew Littlewood-Robbinson tableauxes
         */
        std::vector<LRSkewTableaux> getAbleTableauxes() const;

        /**
         * @brief Get the Littlewood-Robbinson Coefficient
         *
         * @return Littlewood-Robbinson Coefficient
         */
        int getCoefficient() const;

    private:
        /**
         * @brief
         *
         * @return the whole words satisfying weight
         */
        std::vector<RowWord> rowWordCandidates() const;
    };
}