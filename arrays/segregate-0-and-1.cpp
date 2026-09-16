// Problem: Segregate 0s and 1s
// Difficulty: Easy
// Topic: Arrays
// Platform: GeeksForGeeks
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void segregate0and1(vector<int>& arr) {
        int n = arr.size();
        int j = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] != 1) {
                swap(arr[i], arr[j]);
                j++;
            }
        }
    }
};

int main() {
    Solution solution;
    vector<int> arr = {0, 1, 0, 1, 1, 0};

    solution.segregate0and1(arr);

    for (int value : arr) {
        cout << value << " ";
    }
    cout << '\n';

    return 0;
}
