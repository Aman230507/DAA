//AMIT RAJ 25/DA/013
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSortRecursive(vector<int>& arr, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSortRecursive(arr, left, mid);
    mergeSortRecursive(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void mergeSortIterative(vector<int>& arr) {
    int n = arr.size();

    for (int width = 1; width < n; width *= 2) {
        for (int left = 0; left < n - 1; left += 2 * width) {
            int mid = min(left + width - 1, n - 1);
            int right = min(left + 2 * width - 1, n - 1);

            if (mid < right)
                merge(arr, left, mid, right);
        }
    }
}

void printArray(const vector<int>& arr) {
    cout << "[ ";

    for (int x : arr)
        cout << x << " ";

    cout << "]" << endl;
}

int main() {
    vector<int> original = {
        38, 27, 43, 3, 9, 82, 10, 1, 55, 21
    };

    cout << "===== Merge Sort - Recursive and Iterative ====="
         << endl << endl;

    cout << "Original array: ";
    printArray(original);
    cout << endl;

    vector<int> arrRecursive = original;

    cout << "--- Recursive Merge Sort ---" << endl;

    mergeSortRecursive(
        arrRecursive, 0, arrRecursive.size() - 1
    );

    cout << "Sorted array : ";
    printArray(arrRecursive);
    cout << endl;

    vector<int> arrIterative = original;

    cout << "--- Iterative Merge Sort ---" << endl;

    mergeSortIterative(arrIterative);

    cout << "Sorted array : ";
    printArray(arrIterative);
    cout << endl;

    bool same = (arrRecursive == arrIterative);

    cout << "Recursive and Iterative outputs match: "
         << (same ? "YES" : "NO") << endl;

    return 0;
}