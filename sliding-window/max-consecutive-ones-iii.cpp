// 1004. Max Consecutive Ones III
// https://leetcode.com/problems/max-consecutive-ones-iii/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int high = 0;
        int low = 0;
        int res = 0;
        int zero = 0;
        for (high = 0; high < nums.size(); high++) {
            if (nums[high] == 0) {
                zero++;
            }

            while (zero > k) {
                if (nums[low] == 0) {
                    zero--;
                }
                low++;
            }
            int len = high - low + 1;
            res = max(len, res);
        }
        return res;
    }
};

#include <iostream>
int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;
    cout << sol.longestOnes(nums, k) << endl; // Output: 6
    return 0;
}
