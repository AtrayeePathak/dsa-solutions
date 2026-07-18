#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int prefixSum = 0;
        int count = 0;

        mpp[0] = 1;
        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            int diff = prefixSum - k;
            if (mpp.find(diff) != mpp.end()) {
                count += mpp[diff];
            }
            mpp[prefixSum]++;
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1};
    int k = 2;
    cout << sol.subarraySum(nums, k) << endl;
    return 0;
}
