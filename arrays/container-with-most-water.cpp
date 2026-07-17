// Problem: Container With Most Water
// Difficulty: Medium
// Topic: Arrays / Two Pointers
// Link: https://leetcode.com/problems/container-with-most-water/
// Time Complexity: O(n)
// Space Complexity: O(1)
//
// Approach: Use two pointers from both ends and move the pointer with the smaller height.

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = static_cast<int>(height.size()) - 1;
        int maxWater = 0;

        while (left < right) {
            int width = right - left;
            int currentHeight = min(height[left], height[right]);
            int currentWater = width * currentHeight;

            maxWater = max(maxWater, currentWater);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
};

int main() {
    Solution sol;
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << sol.maxArea(height) << endl;
    return 0;
}
