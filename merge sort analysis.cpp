#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

void combineArrays(vector<int>& data, int start, int middle, int end) {
    int len1 = middle - start + 1;
    int len2 = end - middle;
    vector<int> leftSegment(len1), rightSegment(len2);

    for (int i = 0; i < len1; i++) leftSegment[i] = data[start + i];
    for (int j = 0; j < len2; j++) rightSegment[j] = data[middle + 1 + j];

    int i = 0, j = 0, k = start;
    while (i < len1 && j < len2) {
        if (leftSegment[i] <= rightSegment[j]) data[k++] = leftSegment[i++];
        else data[k++] = rightSegment[j++];
    }
    while (i < len1) data[k++] = leftSegment[i++];
    while (j < len2) data[k++] = rightSegment[j++];
}

void recursiveMergeSort(vector<int>& data, int start, int end) {
    if (start >= end) return;
    int middle = start + (end - start) / 2;
    recursiveMergeSort(data, start, middle);
    recursiveMergeSort(data, middle + 1, end);
    combineArrays(data, start, middle, end);
}

int main() {
    srand(time(0));
    vector<int> testSizes = {100, 500, 1000, 5000, 10000};
    int iterationCount = 10;

    cout << "Merge Sort Performance Analysis:" << endl;
    cout << "Size\tAvg Time (milliseconds)" << endl;

    for (int size : testSizes) {
        double totalTime = 0;
        for (int i = 0; i < iterationCount; i++) {
            vector<int> data(size);
            for (int j = 0; j < size; j++) data[j] = rand() % 100000 + 1;

            auto start = chrono::high_resolution_clock::now();
            recursiveMergeSort(data, 0, size - 1);
            auto end = chrono::high_resolution_clock::now();

            totalTime += chrono::duration_cast<chrono::milliseconds>(end - start).count();
        }
        cout << size << "\t" << totalTime / iterationCount << endl;
    }

    return 0;
}
