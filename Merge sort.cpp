#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i) R[i] = arr[mid + 1 + i];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    int N;
    cout << "Enter number of elements (N): ";
    cin >> N;

    vector<int> arr(N);
    srand(time(0));
    for (int i = 0; i < N; ++i)
        arr[i] = rand() % 1000;

    auto start = chrono::high_resolution_clock::now();
    mergeSort(arr, 0, N - 1);
    auto end = chrono::high_resolution_clock::now();

    double duration = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;

    cout << "Sorted array:\n";
    for (int num : arr) cout << num << " ";
    cout << "\nTime taken: " << duration << " ms" << endl;

    return 0;
}