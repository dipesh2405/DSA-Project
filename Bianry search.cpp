#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
using namespace std;

int performBinarySearch(const vector<int>& data, int key) {
    int low = 0, high = data.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (data[mid] == key) return mid;
        else if (data[mid] < key) low = mid + 1;
        else high = mid - 1;
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
    int index = performBinarySearch(data, key);
    auto endTime = chrono::high_resolution_clock::now();

    double elapsedTime = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count() / 1000.0;

    cout << (index != -1 ? "Element found at index " + to_string(index) : "Element not found") << endl;
    cout << "Execution time: " << elapsedTime << " ms" << endl;

    return 0;
}