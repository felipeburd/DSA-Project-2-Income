//CITATION: The skeleton for this code was taken from Sorting lecture slide. Generative AI was used but only to confirm the code is correct and without any errors.
#include "quickSort.h"
#include <algorithm>
#include <vector>
using namespace std;

void incomeQuickSort(vector<int>& dataArray, int beginning, int end) {
    int l = beginning;
    int r = end;
    int pivot = dataArray[(beginning + end) / 2];
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
        incomeQuickSort(dataArray, beginning, r);
    }
    if (l < after) {
        incomeQuickSort(dataArray, l, end);
    }
}
