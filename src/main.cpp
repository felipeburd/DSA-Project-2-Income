#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include "mergeSort.h"
#include "quickSort.h"


using namespace std;

static vector<int> loadIncomes(const string& relPath) {
    // Try relative to project root
    ifstream in(relPath);
    if (!in) {
        // Try relative to build folder
        in.clear();
        in.open("../" + relPath);
    }
    vector<int> v; int x;
    while (in >> x) v.push_back(x);
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
    cout << "Enter dataset path [default: resources/income_sample.txt]: " << flush;

    string path;
    {
        string line;
        if (!getline(cin, line)) return 0;
        path = line.empty() ? "resources/income_sample.txt" : line;
    }

    vector<int> incomes = loadIncomes(path);
    if (incomes.empty()) {
        cerr << "Could not read data from '" << path << "' or file is empty.\n";
        return 1;
    }
    cout << "Loaded " << incomes.size() << " records.\n";

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

    cout << "First 10 values after sort: ";
    for (size_t i = 0; i < work.size() && i < 10; ++i) {
        cout << work[i] << (i + 1 < work.size() && i + 1 < 10 ? ' ' : '\n');
    }
}
