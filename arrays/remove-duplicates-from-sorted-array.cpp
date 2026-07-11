// Problem: Remove Duplicates from Sorted Array
// Difficulty: Easy
// Topic: Arrays
// Approach: Use two pointers to keep unique elements in-place and return the new length

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int l = 1;

        for (int r = 1; r < n; r++) {
            if (nums[r] != nums[r - 1]) {
                nums[l] = nums[r];
                l++;
            }
        }
        return l;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4};

    int newLength = sol.removeDuplicates(nums);

    cout << "New length: " << newLength << '\n';
    cout << "Modified array: ";
    for (int i = 0; i < newLength; ++i) {
        cout << nums[i] << " ";
    }
    cout << '\n';

    return 0;
}
