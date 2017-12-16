#ifndef ZMPO3_HOME_SORTUTILS_H
#define ZMPO3_HOME_SORTUTILS_H


#include <vector>
#include "Comparator.h"

namespace SortUtils {
    template<typename T>
    void bubbleSort(std::vector<T>& vectorToSort, ComparatorUtils::comparator<T> comparator) {
        auto isSorted = false;
        auto bottomBound =  0;
        auto lastSwapDown = 0;
        auto lastSwapUp = bottomBound;
        auto topBound = vectorToSort.size();
        while (!isSorted){
            isSorted = true;
            for (auto index = lastSwapDown; index < topBound - 1; index++) {
                if (comparator(vectorToSort.at(index), vectorToSort.at(index + 1)) > 0) {
                    std::swap(vectorToSort.at(index), vectorToSort.at(index + 1));
                    isSorted = false;
                    lastSwapUp = index;
                }
            }
            topBound--;

            if (!isSorted) {
                for (auto index = lastSwapUp; index > bottomBound; index--) {
                    if (comparator(vectorToSort.at(index - 1), vectorToSort.at(index)) > 0) {
                        std::swap(vectorToSort.at(index - 1), vectorToSort.at(index));
                        isSorted = false;
                        lastSwapDown = index;
                    }
                }
                bottomBound++;
            }
        }
    }
};

#endif //ZMPO3_HOME_SORTUTILS_H
