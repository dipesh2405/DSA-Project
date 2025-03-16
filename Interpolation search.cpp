#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
using namespace std;

int performInterpolationSearch(const vector<int>& data, int key) {
    int low = 0, high = data.size() - 1;
    while (low <= high && key >= data[low] && key <= data[high]) {
        if (data[high] == data[low]) return (data[low] == key) ? low : -1;
        int pos = low + ((key - data[low]) * (high - low)) / (data[high] - data[low]);
        if (data[pos] == key) return pos;
        else if (data[pos] < key) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
}

int main() {
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;

    vector<int> data(size);
    srand(time(0));
    for (int i = 0; i < size; ++i)
        data[i] = rand() % 1000;

    sort(data.begin(), data.end());

    int key;
    cout << "Enter the number to search: ";
    cin >> key;

    auto startTime = chrono::high_resolution_clock::now();
    int index = performInterpolationSearch(data, key);
    auto endTime = chrono::high_resolution_clock::now();

    double elapsedTime = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count() / 1000.0;

    cout << (index != -1 ? "Element found at index " + to_string(index) : "Element not found") << endl;
    cout << "Execution time: " << elapsedTime << " ms" << endl;

    return 0;
}
