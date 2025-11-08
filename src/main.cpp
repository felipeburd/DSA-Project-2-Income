#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <random>
#include <sstream>
#include "mergeSort.h"
#include "quickSort.h"


using namespace std;

static vector<int> generateIncomes(size_t n){
    vector<int> v; 
    v.reserve(n); 

    mt19937 rng(123); // used https://cplusplus.com/reference/random/mt19937/ 
    uniform_int_distribution<int> dist(50000, 200000);

    for(size_t i = 0; i < n; ++i){
        v.push_back(dist(rng));
    }
    return v; 
}


static bool isSorted(const vector<int>& a) {
    for (size_t i = 1; i < a.size(); ++i)
        if (a[i-1] > a[i]) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== Income Sort Interface (Project 2) ===\n";
    cout << "Enter n to generate (default 100000): " << flush;
    size_t n = 100000;
    {
        string line;
        if(!getline(cin, line)) return 0;
        if(!line.empty()) {
            stringstream ss(line);
            size_t tmp;
            if(ss >> tmp) n = tmp; 
        }
    }
    vector<int> incomes = generateIncomes(n);
    cout << "Generated " << incomes.size() << " incomes.\n";

    cout << "Choose algorithm:\n";
    cout << " 1) Merge Sort\n";
    cout << " 2) Quick Sort\n";
    cout << "Selection: " << flush;

    int choice = 1;
    if (!(cin >> choice)) choice = 1;
    cout << "\n";

    // Make a working copy so we can time fairly without mutating the original
    auto work = incomes;

    auto t0 = chrono::high_resolution_clock::now();
    if (choice == 2) {
        incomeQuickSort(work, 0, (int)work.size() - 1);
    } else {
        mergeSort(work, 0, (int)work.size() - 1);
    }
    auto t1 = chrono::high_resolution_clock::now();
    auto ms = chrono::duration_cast<chrono::milliseconds>(t1 - t0).count();

    cout << (choice == 2 ? "Quick Sort" : "Merge Sort") << " finished in " << ms << " ms\n";
    cout << (isSorted(work) ? "Sorted [OK]\n" : "Not sorted [X]\n");

    cout << "First 100 values after sort: ";
    for (size_t i = 0; i < work.size() && i < 100; ++i) {
        cout << work[i] << (i + 1 < work.size() && i + 1 < 100 ? ' ' : '\n');
    }
}
