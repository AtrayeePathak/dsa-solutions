#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

int maxsum (vector<int>& a){
int bestEnd=a[0];
int ans=a[0];
for(int i=1;i<a.size();i++){
    int v1=bestEnd+a[i];
    int v2= a[i];
    bestEnd=max(v1,v2);
    ans=max(ans,bestEnd);
}
return ans;

}

int minsum (vector<int>& a){
int bestEnd=a[0];
int ans=a[0];
for(int i=1;i<a.size();i++){
    int v1=bestEnd+a[i];
    int v2= a[i];
    bestEnd=min(v1,v2);
    ans=min(ans,bestEnd);
}
return ans;

}
    int maxAbsoluteSum(vector<int>& nums) {
       int mini=minsum(nums);
       int maxi=maxsum(nums);
       int ans=max(maxi,abs(mini));
         return ans;
    }
  
};

int main() {
    Solution sol;
    vector<int> nums = {1, -3, 2, 3, -4};
    cout << "Max Absolute Sum: " << sol.maxAbsoluteSum(nums) << endl;
    return 0;
}
