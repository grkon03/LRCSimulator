#include "LRSkewTableaux.hpp"
#include <tuple>

namespace LRCSim
{
    namespace
    {
        SkewDiagram extractSkewDiagram(SSTabSim::MTab mtab)
        {
            DiagramShape hs, cs;
            SSTabSim::TableauxShape ts = mtab.getShape();

            int hnum;
            bool emp;

            for (auto r : ts)
            {
                hnum = 0;
                cs.push_back(r.size());
                emp = true;
                for (auto v : r)
                {
                    if (v <= 0)
                        if (emp)
                            ++hnum;
                        else
                            throw "Bad shaped MTab as SkewDiagram";
                    else
                        emp = false;
                }
                hs.push_back(hnum);
            }

            return SkewDiagram(hs, cs);
        }

        RowWord extractRowWord(SSTabSim::MTab mtab)
        {
            RowWord rw;
            SSTabSim::TableauxShape ts = mtab.getShape();

            std::reverse(ts.begin(), ts.end());

            for (auto r : ts)
            {
                for (auto v : r)
                {
                    if (v > 0)
                        rw.push_back(v);
                }
            }

            return rw;
        }
    }

    LRSkewTableaux::LRSkewTableaux(DiagramShape shape, DiagramShape hole, RowWord rowWord)
        : SkewDiagram(shape, hole), rowWord(rowWord)
    {
        if (!isWellNumbered())
            throw "Bad numbered shape";
    }

    LRSkewTableaux::LRSkewTableaux(YoungDiagram shape, YoungDiagram hole, RowWord rowWord)
        : SkewDiagram(shape, hole), rowWord(rowWord)
    {
        if (!isWellNumbered())
            throw "Bad numbered shape";
    }

    LRSkewTableaux::LRSkewTableaux(SkewDiagram sd, RowWord rowWord)
        : SkewDiagram(sd), rowWord(rowWord)
    {
        if (!isWellNumbered())
            throw "Bad numbered shape";
    }

    LRSkewTableaux::LRSkewTableaux(SSTabSim::MTab mtab)
        : SkewDiagram(extractSkewDiagram(mtab)), rowWord(extractRowWord(mtab))
    {
        if (!isWellNumbered())
            throw "Bad numbered shape";
    }

    LRSkewTableaux::LRSkewTableaux(SSTabSim::TableauxShape ts)
        : LRSkewTableaux(SSTabSim::MTab(ts)) {}

    LRSkewTableaux::LRSkewTableaux(const LRSkewTableaux &lrst)
        : SkewDiagram(lrst), rowWord(lrst.rowWord)
    {
        if (!isWellNumbered())
            throw "Bad numbered shape";
    }

    RowWord LRSkewTableaux::getRowWord() const { return rowWord; }

    void LRSkewTableaux::setRowWord(RowWord rw)
    {
        this->rowWord = rw;
        if (!isWellNumbered())
            throw "Bad numberd shape";
    }

    bool LRSkewTableaux::isWellNumbered() const
    {
        if (sizeExceptHole() != rowWord.size())
            return false;

        SSTabSim::MTab mtab = SSTabSim::MTab(*this);
        SSTabSim::TableauxShape ts = mtab.getShape();
        int max = 0;

        for (auto r : ts)
        {
            for (auto v : r)
            {
                max = (v > max) ? v : max;
            }
        }

        int i, j, tssize = ts.size();

        for (i = 0; i < tssize; ++i)
        {
            for (j = 0; j < ts[i].size(); ++j)
            {
                if (ts[i][j] <= 0)
                    ts[i][j] = max + tssize - i;
            }
        }

        try
        {
            SSTabSim::SSTab _waste = SSTabSim::SSTab(ts);
        }
        catch (const char *err)
        {
            return false;
        }

        return isLatticeWord(rowWord);
    }

    LRSkewTableaux::operator SSTabSim::MTab() const
    {
        SSTabSim::TableauxShape ts;
        std::vector<int> trow;
        DiagramShape hs = hole.getShape();

        hs.resize(shape.size());

        int i, j, irw = 0;

        for (i = 0; i < shape.size(); ++i)
        {
            trow = std::vector<int>();
            for (j = 0; j < shape[i]; ++j)
            {
                if (j < hs[i])
                    trow.push_back(0);
                else
                    trow.push_back(rowWord[irw++]);
            }
            ts.push_back(trow);
        }

        return SSTabSim::MTab(ts);
    }

    std::ostream &operator<<(std::ostream &os, const LRSkewTableaux &lrst)
    {
        return (os << SSTabSim::MTab(lrst));
    }
}