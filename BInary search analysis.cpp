#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    srand(unsigned(time(0)));
    vector<int> N_vals = {100, 500, 1000, 5000, 10000};
    int iterations = 100000;

    cout << "Binary Search Analysis:\n";
    cout << "Size    Avg Time (microseconds)\n";

    for (int N : N_vals) {
        vector<int> numbers(N);
        for (int k = 0; k < N; ++k) numbers[k] = rand() % 100000 + 1;
        sort(numbers.begin(), numbers.end());

        auto start_time = chrono::high_resolution_clock::now();
        for (int j = 0; j < iterations; ++j) {
            int target = numbers[rand() % N];
            binarySearch(numbers, target);
        }
        auto end_time = chrono::high_resolution_clock::now();

        double elapsed_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
        double average_time = elapsed_time / iterations;

        cout << N << "      " << fixed << setprecision(3) << average_time << endl;
    }

    return 0;
}
