// Problem: Maximum Subarray Sum of Fixed Size K
// Difficulty: Easy
// Topic: Sliding Window

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int low =0;
        int high=k-1;
        int sum=0;
        int res=INT_MIN;
        int n=arr.size();
        for(int i=0;i<=high;i++){
           sum=sum+arr[i];//get my first initial sum
        }
           
           while(high<n){//sliding window alogo
              res=max(res,sum);
              low++;
              high++;
           
              sum=sum-arr[low-1];
              sum=sum+arr[high];
           }
        
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> arr = {2, 3, 5, 1, 6, 4};
    int k = 3;

    cout << solution.maxSubarraySum(arr, k) << '\n';

    return 0;
}
