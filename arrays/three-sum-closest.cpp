#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int min_diff=INT_MAX;
        int result=0;
        for(int i=0;i<n-2;i++){

            int left=i+1;
            int right=n-1;

            while(left<right){
            int sum= nums[i]+nums[left]+nums[right];
            int diff=abs(sum-target);
            if(diff<min_diff){
                min_diff=diff;
                result=sum;
            }
                if(sum<target){
                    left++;
                }
                else if(sum>target){
                    right--;
                }

                else{
                   return sum;
                }
            }
           
        }
    return result ;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int& value : nums) {
        cin >> value;
    }

    int target;
    cin >> target;

    Solution solution;
    cout << solution.threeSumClosest(nums, target) << '\n';

    return 0;
}
