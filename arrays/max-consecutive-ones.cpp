#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Returns the longest run of consecutive ones in the array.
    int consecutiveOnes(vector<int>& arr) {
        int current = 0;
        int best = 0;

        for (int value : arr) {
            if (value == 1) {
                current++;
            } else {
                current = 0;
            }
            best = max(best, current);
        }

        return best;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 1, 0, 1, 1, 1, 0, 1};
    cout << sol.consecutiveOnes(arr) << endl;
    return 0;
}
