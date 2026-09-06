#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0;
        int j=0;
        vector<int> res(m + n);
        int id = 0;
        while (i<m and j<n ){
            if(nums1[i]<=nums2[j]){
             res[id]=nums1[i];
             id++;
             i++;
            }
            else{
                res[id]=nums2[j];
                id++;
                j++;
            }

        }
        while(i<m){
            res[id]=nums1[i];
            id++;
            i++;
        }
        while(j<n){
            res[id]=nums2[j];
            id++;
            j++;
        }
        nums1=res;
    }
};

int main() {
    int m;
    cin >> m;

    vector<int> nums1(m);
    for (int& value : nums1) {
        cin >> value;
    }

    int n;
    cin >> n;

    vector<int> nums2(n);
    for (int& value : nums2) {
        cin >> value;
    }

    Solution solution;
    solution.merge(nums1, m, nums2, n);

    for (int value : nums1) {
        cout << value << " ";
    }
    cout << '\n';

    return 0;
}
