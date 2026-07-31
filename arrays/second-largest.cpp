#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
     
     int large=-1;
     int second=-1;
     int n=arr.size();
     
     
     for(int i=0;i<n;i++){
         if(arr[i]>large){
           
             second=large;
             large=arr[i];
         }
         else  if(arr[i]<large && arr[i]>second){
             second=arr[i];
         }
     }
     
     return second;
        
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> arr1 = {12, 35, 1, 10, 34, 1};
    cout << "Second largest in {12, 35, 1, 10, 34, 1} is: " << solution.getSecondLargest(arr1) << endl;
    
    // Test case 2
    vector<int> arr2 = {10, 5, 10};
    cout << "Second largest in {10, 5, 10} is: " << solution.getSecondLargest(arr2) << endl;
    
    return 0;
}
