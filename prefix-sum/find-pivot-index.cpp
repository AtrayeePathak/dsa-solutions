// Problem: Find Pivot Index
// LeetCode: 724
// Difficulty: Easy
// Topic: Prefix Sum
// Link: https://leetcode.com/problems/find-pivot-index/
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        int left=0;
        int right=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
        }

        for(int i=0;i<nums.size();i++){
        
          right=sum-left-nums[i];
          if(left==right){
            return i;
          }
          left=left+nums[i];
        }
        return -1;

    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    cout << sol.pivotIndex(nums) << endl;
    return 0;
}
