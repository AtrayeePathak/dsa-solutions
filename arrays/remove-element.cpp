// Problem: Remove Element
// Difficulty: Easy
// Topic: Arrays
// Approach: In-place overwrite using a write pointer to skip target value

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                nums[k]=nums[i];
                k++;
            }
        }
        return k;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;

    cout << "Before: ";
    for (int x : nums) cout << x << " ";
    cout << '\n';

    int k = sol.removeElement(nums, val);

    cout << "After:  ";
    for (int i = 0; i < k; i++) cout << nums[i] << " ";
    cout << '\n';
    cout << "k = " << k << '\n';

    return 0;
}
