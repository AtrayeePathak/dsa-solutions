#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

int maxSum(vector<int>& a1){
    int bestEnd=a1[0];
    int ans=a1[0];
    for(int i=1;i<a1.size();i++){
        int v1=bestEnd+a1[i];
        int v2=a1[i];
        bestEnd=max(v1,v2);
        ans=max(bestEnd,ans);
    }
    return ans;
}
int minsumcircular(vector<int>& a1){
    int totalSum=a1[0];
    int bestEnd=a1[0];
    int ans=a1[0];
    int finalans=0;
    for(int i=1;i<a1.size();i++){
        totalSum=totalSum+a1[i];
        int v1=bestEnd+a1[i];
        int v2=a1[i];
        bestEnd=min(v1,v2);
        ans=min(bestEnd,ans);
      
    }
    return totalSum-ans;
}


    int maxSubarraySumCircular(vector<int>& nums) {
        int v1=maxSum(nums);
        int v2=minsumcircular(nums);
        if(v1<0){
            return v1;
        }
        int ans=max(v1,v2);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5, -3, 5};
    cout << "Max Circular Subarray Sum: " << sol.maxSubarraySumCircular(nums) << endl;
    return 0;
}
