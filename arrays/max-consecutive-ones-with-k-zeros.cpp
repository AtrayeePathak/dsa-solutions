#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestOnesWithKZeros(const vector<int>& nums, int k) {
        int l = 0;
        int zero = 0;
        int maxlength = 0;

        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] == 0) {
                zero++;
            }

            while (zero > k) {
                if (nums[l] == 0) {
                    zero--;
                }
                l++;
            }

            maxlength = max(maxlength, r - l + 1);
        }

        return maxlength;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 0, 1, 1, 0, 1, 0, 1, 1, 1};
    int k = 3;
    cout << sol.longestOnesWithKZeros(nums, k) << endl;
    return 0;
}
