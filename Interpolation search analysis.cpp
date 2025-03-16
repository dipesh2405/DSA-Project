#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

int performInterpolationSearch(const vector<int>& data, int key) {
    int low = 0, high = data.size() - 1;
    while (data[high] != data[low] && key >= data[low] && key <= data[high]) {
        int pos = low + ((key - data[low]) * (high - low)) / (data[high] - data[low]);
        if (pos < low || pos > high) return -1;
        if (data[pos] == key) return pos;
        else if (data[pos] < key) low = pos + 1;
        else high = pos - 1;
    }
    return (data[low] == key) ? low : -1;
}

int main() {
    srand(time(0));
    vector<int> testSizes = {100, 500, 1000, 5000, 10000};
    int iterations = 100000;

    cout << "Interpolation Search Performance Analysis:" << endl;
    cout << "Size\tAvg Time (microseconds)" << endl;

    for (int size : testSizes) {
        vector<int> data(size);
        for (int i = 0; i < size; i++) data[i] = rand() % 100000 + 1;
        sort(data.begin(), data.end());

        auto start = chrono::high_resolution_clock::now();
        for (int i = 0; i < iterations; i++) {
            int key = data[rand() % size];
            performInterpolationSearch(data, key);
        }
        auto end = chrono::high_resolution_clock::now();

        double totalTime = chrono::duration_cast<chrono::microseconds>(end - start).count();
        double avgTime = totalTime / iterations;
        cout << size << "\t" << avgTime << endl;
    }
