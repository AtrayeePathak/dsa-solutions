#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int minSubarraySum(vector<int> &arr) {
        int bestEnd=arr[0];
        int ans=arr[0];
        
        for(int i=1;i<arr.size();i++){
            int v1=bestEnd+arr[i];
            int v2=arr[i];
             bestEnd=min(v1,v2);
            ans=min(bestEnd,ans);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {3, -4, 2, -3, -1, 7, -5};
    cout << "Min Subarray Sum: " << sol.minSubarraySum(arr) << endl;
    return 0;
}
