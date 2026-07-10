#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void quickSort(vector<int>& arr, int low, int high) {

        // Base Case
        if (low >= high)
            return;

        // Find pivot index
        int partitionIndex = partition(arr, low, high);

        // Sort left half
        quickSort(arr, low, partitionIndex - 1);

        // Sort right half
        quickSort(arr, partitionIndex + 1, high);
    }

    int partition(vector<int>& arr, int low, int high) {

        int pivot = arr[low];
        int i = low;
        int j = high;

        while (i < j) {

            // Move i to the right
            while (i <= high - 1 && arr[i] <= pivot)
                i++;

            // Move j to the left
            while (j >= low + 1 && arr[j] > pivot)
                j--;

            // Swap if needed
            if (i < j)
                swap(arr[i], arr[j]);
        }

        // Place pivot at its correct position
        swap(arr[low], arr[j]);

        return j;
    }
};

int main() {

    vector<int> arr = {4, 1, 3, 9, 7};

    Solution obj;

    cout << "Before Sorting:\n";
    for (int x : arr)
        cout << x << " ";

    cout << "\n";

    obj.quickSort(arr, 0, arr.size() - 1);

    cout << "After Sorting:\n";
    for (int x : arr)
        cout << x << " ";

    cout << "\n";

    return 0;
}