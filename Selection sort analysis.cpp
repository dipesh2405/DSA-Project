#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

void performSelectionSort(vector<int>& data) {
    int length = data.size();
    for (int i = 0; i < length - 1; i++) {
        int smallestIdx = i;
        for (int j = i + 1; j < length; j++) {
            if (data[j] < data[smallestIdx]) smallestIdx = j;
        }
        swap(data[smallestIdx], data[i]);
    }
}

int main() {
    srand(time(0));
    vector<int> testSizes = {100, 500, 1000, 5000, 10000};
    int iterationCount = 10;

    cout << "Selection Sort Performance Analysis:" << endl;
    cout << "Size\tAvg Time (milliseconds)" << endl;

    for (int size : testSizes) {
        double totalTime = 0;
        for (int i = 0; i < iterationCount; i++) {
            vector<int> data(size);
            for (int j = 0; j < size; j++) data[j] = rand() % 100000 + 1;

            auto start = chrono::high_resolution_clock::now();
            performSelectionSort(data);
            auto end = chrono::high_resolution_clock::now();

            totalTime += chrono::duration_cast<chrono::milliseconds>(end - start).count();
        }
        cout << size << "\t" << totalTime / iterationCount << endl;
    }

    return 0;
}
