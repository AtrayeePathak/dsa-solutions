// LeetCode 287 - Find the Duplicate Number
// https://leetcode.com/problems/find-the-duplicate-number/
// Approach: Floyd's Cycle Detection (Tortoise and Hare)
// Time: O(n) | Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        while(true) {
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];

            if(slow == fast) {
                slow = 0;
                while(slow != fast) {
                    slow = nums[slow];
                    fast = nums[fast];
                }
                return slow;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;

    // Example 1: [1,3,4,2,2] -> duplicate is 2
    vector<int> nums1 = {1, 3, 4, 2, 2};
    cout << "Example 1: " << sol.findDuplicate(nums1) << endl;

    // Example 2: [3,1,3,4,2] -> duplicate is 3
    vector<int> nums2 = {3, 1, 3, 4, 2};
    cout << "Example 2: " << sol.findDuplicate(nums2) << endl;

    // Example 3: [3,3,3,3,3] -> duplicate is 3
    vector<int> nums3 = {3, 3, 3, 3, 3};
    cout << "Example 3: " << sol.findDuplicate(nums3) << endl;

    return 0;
}
