//AMIT RAJ 25/DA/013
#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(const vector<int>& arr) {
    cout << "[ ";
    for (int x : arr)
        cout << x << " ";
    cout << "]" << endl;
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10, 1, 55, 21};

    cout << "===== Quick Sort =====" << endl << endl;
    cout << "Original array: ";
    printArray(arr);

    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted array : ";
    printArray(arr);

    return 0;
}