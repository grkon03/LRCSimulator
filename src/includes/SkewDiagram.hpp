#pragma once

#include "YoungDiagram.hpp"

namespace LRCSim
{
    /**
     * @brief SkewDiagram
     *
     * @note 'Container' means a Young diagram in the case of the shape being not holed.
     *
     */
    class SkewDiagram : public YoungDiagram
    {
    protected:
        // variables

        YoungDiagram hole;

    public:
        // constructors

        SkewDiagram(DiagramShape, DiagramShape);
        SkewDiagram(YoungDiagram, YoungDiagram);

        SkewDiagram(const SkewDiagram &);

        // functions

        /**
         * @brief Get the container shape
         *
         * @return YoungDiagram
         */
        YoungDiagram getContainer() const;

        /**
         * @brief Get the hole
         *
         * @return hole
         */
        YoungDiagram getHole() const;

        /**
         * @brief Set the container
         *
         * @param container the container
         */
        void setContainer(YoungDiagram container);

        /**
         * @brief Set the hole
         *
         * @param hole the hole
         */
        void setHole(YoungDiagram hole);

        /**
         * @brief verify whether the hole is contained by main diagram
         *
         * @return whether the hole is contained by main diagram
         */
        bool isWellHoled() const;
    };

    std::ostream &operator<<(std::ostream &, const SkewDiagram &);
}