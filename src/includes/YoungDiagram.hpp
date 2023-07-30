#pragma once

#include "types.hpp"

namespace LRCSim
{
    class YoungDiagram
    {
    protected:
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

        // static functions

        /**
         * @brief enumerate all partitions of the size
         *
         * @param size the size of partitions
         * @return paritions list
         */
        static std::vector<YoungDiagram> enumPartitions(unsigned int size);

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

        /**
         * @brief Get the height
         *
         * @return the height
         */
        int height() const;

        /**
         * @brief Get the size
         *
         * @return the size
         */
        int size() const;
    };

    // operator

    std::ostream &operator<<(std::ostream &os, const YoungDiagram &yd);
}