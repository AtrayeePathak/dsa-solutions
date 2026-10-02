// 713. Subarray Product Less Than K
// https://leetcode.com/problems/subarray-product-less-than-k/

#include <vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1)
            return 0;
        int high = 0;
        int low = 0;
        int count = 0;
        int pro = 1;
        for (high = 0; high < nums.size(); high++) {
            pro = pro * nums[high];

            while (pro >= k) {
                pro = pro / nums[low];
                low++;
            }

            count = count + (high - low + 1);
        }
        return count;
    }
};

#include <iostream>
int main() {
    Solution sol;
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;
    cout << sol.numSubarrayProductLessThanK(nums, k) << endl; // Output: 8
    return 0;
}
