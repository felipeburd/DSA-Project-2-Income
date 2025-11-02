#include "quickSort.h"

void quickSort(vector<int>& dataArray, int left, int right) {
    int i = left;
    int j = right;

    // Pivot = middle element
    int pivot = Dataarr[(left + right) / 2];

    // Partition
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    // Recursively sort each side
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}

//check for pull

