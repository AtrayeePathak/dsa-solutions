#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
      int maxEnd=nums[0];
      int minEnd=nums[0];
      int ans=nums[0];
      for(int i=1;i<nums.size();i++){
        int v1=minEnd*nums[i];
        int v2=maxEnd*nums[i];
        int v3=nums[i];
        maxEnd=max(v1,(max(v2,v3)));
        minEnd=min(v1,min(v2,v3));

        ans=max(ans,maxEnd);
      }
      return ans;

    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, -2, 4};
    cout << "Max Product Subarray: " << sol.maxProduct(nums) << endl;
    return 0;
}
