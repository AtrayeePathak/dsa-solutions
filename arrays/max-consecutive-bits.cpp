#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxConsecBits(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;

        int maxi = 1;
        int count = 1;

        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i - 1]) {
                count++;
            } else {
                count = 1;
            }
            maxi = max(maxi, count);
        }

        return maxi;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 1, 0, 0, 0, 1, 1, 1, 1};
    cout << sol.maxConsecBits(arr) << endl;
    return 0;
}
