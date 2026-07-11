// Problem: Move Zeroes
// Difficulty: Easy
// Topic: Arrays
// Approach: In-place two-pointer swap to move zeros to the end

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 1, 0, 3, 12};

    cout << "Before: ";
    for (int x : nums) cout << x << " ";
    cout << '\n';

    sol.moveZeroes(nums);

    cout << "After:  ";
    for (int x : nums) cout << x << " ";
    cout << '\n';

    return 0;
}
