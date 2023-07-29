#include "SkewDiagram.hpp"

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

    SkewDiagram::SkewDiagram(DiagramShape shape, DiagramShape hole)
        : YoungDiagram(shape), hole(hole)
    {
        if (!isWellHoled())
            throw "Bad holed diagram";
    }

    SkewDiagram::SkewDiagram(YoungDiagram shape, YoungDiagram hole)
        : YoungDiagram(shape), hole(hole)
    {
        if (!isWellHoled())
            throw "Bad holed diagram";
    }

    SkewDiagram::SkewDiagram(const SkewDiagram &sd) : SkewDiagram(sd.shape, sd.hole) {}

    YoungDiagram SkewDiagram::getContainer() const
    {
        return YoungDiagram(*this);
    }

    YoungDiagram SkewDiagram::getHole() const
    {
        return hole;
    }

    void SkewDiagram::setContainer(YoungDiagram container)
    {
        setShape(container.getShape());
        if (!isWellHoled())
            throw "Bad holed diagram";
    }

    void SkewDiagram::setHole(YoungDiagram hole)
    {
        this->hole = hole;
        if (!isWellHoled())
            throw "Bad holed diagram";
    }

    bool SkewDiagram::isWellHoled() const
    {
        if (height() < hole.height())
            return false;

        DiagramShape hs = hole.getShape();

        for (int i = 0; i < height(); ++i)
        {
            if (shape[i] < hs[i])
                return false;
        }

        return true;
    }

    std::ostream &operator<<(std::ostream &os, const SkewDiagram &sd)
    {
        DiagramShape hs = sd.getHole().getShape();
        DiagramShape cs = sd.getContainer().getShape();

        int ch = cs.size();

        if (ch == 0)
            return os;

        hs.resize(ch, 0);

        os << std::string(" 　") * hs[0] << std::string(" ＿") * (cs[0] - hs[0]) << std::endl;

        for (int i = 0; i < ch; ++i)
        {
            if (i == ch)
                os << std::string(" 　") * hs[i] << std::string("|＿") * (cs[i] - hs[i]);
            else
                os << std::string(" 　") * hs[i + 1]
                   << std::string(" ＿") * (hs[i] - hs[i + 1])
                   << std::string("|＿") * (cs[i] - hs[i]);

            os << "|" << std::endl;
        }

        return os;
    }
}