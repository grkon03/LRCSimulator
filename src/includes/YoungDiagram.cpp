#include "YoungDiagram.hpp"

namespace LRCSim
{
    YoungDiagram::YoungDiagram(DiagramShape shape) : shape(shape)
    {
        deleteEmptyRows();
        if (!isWellShaped())
            throw "Bad shaped diagram";
    }

    YoungDiagram::YoungDiagram(const YoungDiagram &yd) : YoungDiagram(yd.shape){};

    DiagramShape YoungDiagram::getShape() const { return shape; }

    void YoungDiagram::setShape(DiagramShape shape)
    {
        this->shape = shape;

        if (!isWellShaped())
            throw "Bad shaped diagram";
    }

    void YoungDiagram::deleteEmptyRows()
    {
        std::remove_if(std::begin(shape), std::end(shape), [](int e)
                       { return (e <= 0); });
    }

    bool YoungDiagram::isWellShaped() const { return isYoung(shape); }

    int YoungDiagram::height() const { return shape.size(); }

    std::ostream &operator<<(std::ostream &os, const YoungDiagram &yd)
    {
        os << yd.getShape();
        return os;
    }
}