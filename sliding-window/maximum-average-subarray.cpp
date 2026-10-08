// LeetCode 643 - Maximum Average Subarray I
// https://leetcode.com/problems/maximum-average-subarray-i/
// Approach: Fixed-size Sliding Window
// Time: O(n) | Space: O(1)

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int high=k-1;
        int low=0;
        int sum=0;
        int res=INT_MIN;
        for(int i=low;i<=high;i++){
         sum=sum+nums[i];
        }
          while(high<nums.size()){
             res=max(res,sum);
             low++;
             high++;
             if(high==nums.size())
             break;
            sum=sum-nums[low-1];
            sum=sum+nums[high];
          }
        
        return (double)res/k;
    }
};

int main() {
    Solution sol;

    // Example 1: nums = [1,12,-5,-6,50,3], k = 4 -> Output: 12.75
    vector<int> nums1 = {1, 12, -5, -6, 50, 3};
    cout << "Example 1: " << sol.findMaxAverage(nums1, 4) << endl;

    // Example 2: nums = [5], k = 1 -> Output: 5.0
    vector<int> nums2 = {5};
    cout << "Example 2: " << sol.findMaxAverage(nums2, 1) << endl;

    // Example 3: nums = [0,4,0,3,2], k = 1 -> Output: 4.0
    vector<int> nums3 = {0, 4, 0, 3, 2};
    cout << "Example 3: " << sol.findMaxAverage(nums3, 1) << endl;

    return 0;
}
