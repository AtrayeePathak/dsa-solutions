// 1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
// https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/

#include <vector>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int low = 0;
        int high = k - 1;
        int count = 0;
        int sum = 0;
        for (int i = low; i <= high; i++) {
            sum = sum + arr[i]; // first window
        }

        while (high < arr.size()) {
            if (sum >= threshold * k) {
                count++;
            }
            low++;
            high++;
            if (high == arr.size())
                break;

            sum = sum - arr[low - 1];
            sum = sum + arr[high];
        }

        return count;
    }
};

#include <iostream>
int main() {
    Solution sol;
    vector<int> arr = {2, 2, 2, 2, 5, 5, 5, 8};
    int k = 3;
    int threshold = 4;
    cout << sol.numOfSubarrays(arr, k, threshold) << endl; // Output: 3
    return 0;
}
