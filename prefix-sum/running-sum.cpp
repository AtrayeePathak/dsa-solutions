// Problem: Running Sum of 1d Array
// LeetCode: 1480
// Difficulty: Easy
// Topic: Prefix Sum
// Link: https://leetcode.com/problems/running-sum-of-1d-array/
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> pref(nums.size());
         pref[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            pref[i]=pref[i-1]+nums[i];
        }
        return pref;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = sol.runningSum(nums);
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
