#include "LRCCalculator.hpp"

#include <numeric>
#include <set>

namespace LRCSim
{
    LRCCalculator::LRCCalculator()
        : LRCCalculator({}, {}, {}) {}

    LRCCalculator::LRCCalculator(DiagramShape shape, DiagramShape hole, DiagramShape weight)
        : LRCCalculator(YoungDiagram(shape), YoungDiagram(hole), YoungDiagram(weight)) {}

    LRCCalculator::LRCCalculator(YoungDiagram container, YoungDiagram hole, YoungDiagram weight)
        : LRCCalculator(SkewDiagram(container, hole), weight) {}

    LRCCalculator::LRCCalculator(SkewDiagram sd, DiagramShape weight)
        : LRCCalculator(sd, YoungDiagram(weight)) {}

    LRCCalculator::LRCCalculator(SkewDiagram sd, YoungDiagram weight)
        : SkewDiagram(sd), weight(weight)
    {
        ableTableauxes = std::vector<LRSkewTableaux>();
        coefficient = 0;

        std::vector<RowWord> list = rowWordCandidates();

        for (auto word : list)
        {
            try
            {
                LRSkewTableaux _try(SkewDiagram(*this), word);
            }
            catch (const char *err)
            {
                continue;
            }

            ableTableauxes.push_back(LRSkewTableaux(SkewDiagram(*this), word));
            ++coefficient;
        }
    }

    LRCCalculator::LRCCalculator(const LRCCalculator &lrcc)
        : SkewDiagram(lrcc), weight(lrcc.weight), ableTableauxes(lrcc.ableTableauxes), coefficient(lrcc.coefficient) {}

    YoungDiagram LRCCalculator::getWeight() const { return weight; }

    std::vector<LRSkewTableaux> LRCCalculator::getAbleTableauxes() const { return ableTableauxes; }

    int LRCCalculator::getCoefficient() const { return coefficient; }

    std::vector<RowWord> LRCCalculator::rowWordCandidates() const
    {
        std::vector<RowWord> candidates;
        std::vector<int> numbers;
        DiagramShape ws = weight.getShape();

        int i, j;

        for (i = 0; i < ws.size(); ++i)
            for (j = 0; j < ws[i]; ++j)
                numbers.push_back(i + 1);

        std::vector<int> indexes(numbers.size());

        std::iota(indexes.begin(), indexes.end(), 0);

        RowWord tempWord;

        do
        {
            tempWord = RowWord();
            for (auto v : indexes)
                tempWord.push_back(numbers[v]);
            candidates.push_back(tempWord);
        } while (std::next_permutation(indexes.begin(), indexes.end()));

        std::set<RowWord> candidatesNoOverlap(candidates.begin(), candidates.end());

        candidates.assign(candidatesNoOverlap.begin(), candidatesNoOverlap.end());

        return candidates;
    }
}