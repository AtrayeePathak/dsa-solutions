// Problem: Subarray Sum Equals K
// LeetCode: 560
// Difficulty: Medium
// Topic: Prefix Sum
// Link: https://leetcode.com/problems/subarray-sum-equals-k/
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0;
        int res=0;
        unordered_map<int,int>f;
        f[0]=1;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            int ques=sum-k;
            int freq=f[ques];
            res=res+freq;
            f[sum]++;

        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1};
    int k = 2;
    cout << sol.subarraySum(nums, k) << endl;
    return 0;
}
