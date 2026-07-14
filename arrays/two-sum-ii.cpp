// Problem: Two Sum II - Input array is sorted
// Difficulty: Easy
// Topic: Arrays
// Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int left = 0;
        int right = n - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                return {left + 1, right + 1};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return {};
    }
};

int main() {
    Solution sol;
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = sol.twoSum(numbers, target);
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
