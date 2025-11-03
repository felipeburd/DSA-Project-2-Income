//CITATION: The skeleton for this code was taken from Sorting lecture slide. Generative AI was used but only to confirm the code is correct and without any errors.
#include "quickSort.h"
#include <algorithm>
#include <vector>
using namespace std;

void incomeQuickSort(vector<int>& dataArray, int before, int after) {
    int l = before;
    int r = after;
    int pivot = dataArray[(before + after) / 2];
    while (l <= r) {
        while (dataArray[l] < pivot) {
            l++;
        }
        while (dataArray[r] > pivot) {
            r--;
        }

        if (l <= r) {
            swap(dataArray[l], dataArray[r]);
            l++;
            r--;
        }
    }
    if (before < r) {
        incomeQuickSort(dataArray, before, r);
    }
    if (l < after) {
        incomeQuickSort(dataArray, l, after);
    }
}
