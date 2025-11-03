#include "mergeSort.h"
#include <vector>
using std::vector;

static void merge(vector<int>& a, int L, int M, int R) {
    int n1 = M - L + 1, n2 = R - M;
    vector<int> left(n1), right(n2);
    for (int i = 0; i < n1; ++i) left[i] = a[L + i];
    for (int j = 0; j < n2; ++j) right[j] = a[M + 1 + j];

    int i = 0, j = 0, k = L;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) a[k++] = left[i++];
        else                     a[k++] = right[j++];
    }
    while (i < n1) a[k++] = left[i++];
    while (j < n2) a[k++] = right[j++];
}

void mergeSort(vector<int>& a, int L, int R) {
    if (L >= R) return;
    int M = L + (R - L) / 2;
    mergeSort(a, L, M);
    mergeSort(a, M + 1, R);
    merge(a, L, M, R);
}
