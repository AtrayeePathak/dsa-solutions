// Problem: Remove Duplicates from Sorted Array
// Difficulty: Easy
// Topic: Arrays
// Approach: Keep the first occurrence of each value in the sorted array

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> removeDuplicates(vector<int> &arr) {
        vector<int>res;
        int officer =0;
             
             int cm=1;
             int n=arr.size();
             res.push_back(arr[0]);
             while(cm<n){
                 if(arr[cm]==arr[cm-1]){
                     cm++;
                     continue;
                 }
                else{
                 arr[officer +1]=arr[cm];
                 officer++;
                 res.push_back(arr[cm]);
                 cm++;
                }
             }

             return res;
        
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int& value : arr) {
        cin >> value;
    }

    Solution sol;
    vector<int> result = sol.removeDuplicates(arr);

    for (int value : result) {
        cout << value << " ";
    }
    cout << '\n';

    return 0;
}
