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

    namespace
    {
        std::vector<YoungDiagram> enumPartitionsMax(unsigned int p, unsigned int max)
        {
            if (p == 0)
                return std::vector<YoungDiagram>();

            if (p == 1)
            {
                if (max == 0)
                    return std::vector<YoungDiagram>();
                else
                    return std::vector<YoungDiagram>{YoungDiagram({1})};
            }

            if (p < max)
                max = p;

            std::vector<YoungDiagram> ret;
            std::vector<YoungDiagram> under;
            DiagramShape tempShape;
            int i;

            for (i = 1; i <= max; ++i)
            {
                under = enumPartitionsMax(p - i, i);
                if (under.size() == 0)
                {
                    ret.push_back(YoungDiagram({i}));
                }

                for (auto yd : under)
                {
                    tempShape = yd.getShape();
                    tempShape.insert(tempShape.begin(), {i});
                    ret.push_back(YoungDiagram(tempShape));
                }
            }

            return ret;
        }
    }

    std::vector<YoungDiagram> YoungDiagram::enumPartitions(unsigned int p)
    {
        return enumPartitionsMax(p, p);
    }

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

    int YoungDiagram::size() const
    {
        int s = 0;

        for (auto v : shape)
        {
            s += v;
        }

        return s;
    }

    std::ostream &operator<<(std::ostream &os, const YoungDiagram &yd)
    {
        os << yd.getShape();
        return os;
    }
}