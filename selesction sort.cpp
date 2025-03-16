#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

void performSelectionSort(vector<int>& data) {
    int length = data.size();
    for (int i = 0; i < length - 1; ++i) {
        int smallestIdx = i;
        for (int j = i + 1; j < length; ++j)
            if (data[j] < data[smallestIdx]) smallestIdx = j;
        swap(data[i], data[smallestIdx]);
    }
}

int main() {
    int size;
    cout << "Enter number of elements: ";
    cin >> size;

    vector<int> data(size);
    srand(time(0));
    for (int i = 0; i < size; ++i)
        data[i] = rand() % 1000;

    auto startTime = chrono::high_resolution_clock::now();
    performSelectionSort(data);
    auto endTime = chrono::high_resolution_clock::now();

    double elapsedTime = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count() / 1000.0;

    cout << "Sorted array:\n";
    for (int num : data) cout << num << " ";
    cout << "\nExecution time: " << elapsedTime << " ms" << endl;

    return 0;
}
