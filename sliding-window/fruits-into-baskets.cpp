// Fruit Into Baskets
// LeetCode #904
// Given an array of integers where each integer represents a type of fruit,
// find the maximum number of fruits you can collect with at most 2 baskets
// (i.e., longest subarray with at most 2 distinct elements).
// Approach: Sliding window with a frequency map. Expand the window by moving `high`,
//           and shrink from `low` whenever the window contains more than 2 distinct fruits.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int high = 0;
        int low = 0;
        int res = INT_MIN;
        int n = fruits.size();
        unordered_map<int, int> f;
        for (high = 0; high < n; high++) {
            f[fruits[high]]++;

            while (f.size() > 2) {
                f[fruits[low]]--;
                if (f[fruits[low]] == 0) {
                    f.erase(fruits[low]);
                }
                low++;
            }
            int len = high - low + 1;
            res = max(len, res);
        }
        return res;
    }
};

int main() {
    Solution sol;

    vector<int> fruits1 = {1, 2, 1};
    cout << "Input: [1, 2, 1]" << endl;
    cout << "Output: " << sol.totalFruit(fruits1) << endl;
    // Expected: 3

    vector<int> fruits2 = {0, 1, 2, 2};
    cout << "\nInput: [0, 1, 2, 2]" << endl;
    cout << "Output: " << sol.totalFruit(fruits2) << endl;
    // Expected: 3

    vector<int> fruits3 = {1, 2, 3, 2, 2};
    cout << "\nInput: [1, 2, 3, 2, 2]" << endl;
    cout << "Output: " << sol.totalFruit(fruits3) << endl;
    // Expected: 4

    vector<int> fruits4 = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    cout << "\nInput: [3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4]" << endl;
    cout << "Output: " << sol.totalFruit(fruits4) << endl;
    // Expected: 5

    return 0;
}
