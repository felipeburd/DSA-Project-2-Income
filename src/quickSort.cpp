#include "quickSort.h"
#include <algorithm>
using std::vector;
using std::swap;

void incomeQuickSort(vector<int>& dataArray, int before, int after) {
    int l = before;
    int r = after;

    // Pivot = middle element
    int pivot = dataArray[(before + after) / 2];

    // Partition
    while (l <= r) {
        while (dataArray[l] < pivot) l++;
        while (dataArray[r] > pivot) r--;

        if (l <= r) {
            swap(dataArray[l], dataArray[r]);
            l++;
            r--;
        }
    }
    if (before < r)
        incomeQuickSort(dataArray, before, r);
    if (l < after)
        incomeQuickSort(dataArray, l, after);
}
