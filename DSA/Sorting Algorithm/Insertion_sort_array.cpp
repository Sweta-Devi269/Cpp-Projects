#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int tmp = i;
        int value = arr[i];

        // Remove the element at index i (like pop(i) in Python)
        arr.erase(arr.begin() + i);

        // Find the correct position in the sorted left part
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] > value) {
                tmp = j;
            }
        }

        // Insert it back at the correct position
        arr.insert(arr.begin() + tmp, value);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    insertionSort(arr);

    cout << "Sorted array: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
