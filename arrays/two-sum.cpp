// Problem: Two Sum
// Difficulty: Easy
// Topic: Arrays
// Link: https://leetcode.com/problems/two-sum/
// Time Complexity: O(n)
// Space Complexity: O(n)
//
// Approach: Use a hashmap to store seen numbers and check if complement exists

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indexMap;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (indexMap.find(complement) != indexMap.end()) {
                return {indexMap[complement], i};
            }
            indexMap[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    vector<int> result = sol.twoSum(nums, 9);
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}