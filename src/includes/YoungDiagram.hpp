#pragma once

#include "types.hpp"

namespace LRCSim
{
    class YoungDiagram
    {
        // variables

        /**
         * @brief shape of the young diagram
         *
         */
        DiagramShape shape;

    public:
        // constructors

        YoungDiagram(DiagramShape);

        YoungDiagram(const YoungDiagram &);

        // functions

        /**
         * @brief Get the shape
         *
         * @return shape
         */
        DiagramShape getShape() const;

        /**
         * @brief Set the shape
         *
         */
        void setShape(DiagramShape);

        /**
         * @brief delete empty rows
         *
         */
        void deleteEmptyRows();

        /**
         * @brief verify whether this is shaped as young diagram
         *
         * @return whether this is shaped as young diagram
         */
        bool isWellShaped() const;
    };

    // operator

    std::ostream &operator<<(std::ostream &os, const YoungDiagram &yd);
}