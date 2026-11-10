#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long totalSum = 0;

        for (int x : arr) {
            totalSum += x;
        }

        // Kadane on two copies
        long long curr = 0;
        long long best = 0;

        for (int i = 0; i < 2 * arr.size(); i++) {
            int x = arr[i % arr.size()];

            curr = max(0LL, curr + x);
            best = max(best, curr);
        }

        // If k = 1, only one copy is allowed
        if (k == 1) {
            curr = 0;
            best = 0;

            for (int x : arr) {
                curr = max(0LL, curr + x);
                best = max(best, curr);
            }

            return best % MOD;
        }

        // If total sum is positive, calculate
        // maximum prefix and suffix
        if (totalSum > 0) {
            long long prefix = 0;
            long long maxPrefix = 0;

            for (int x : arr) {
                prefix += x;
                maxPrefix = max(maxPrefix, prefix);
            }

            long long suffix = 0;
            long long maxSuffix = 0;

            for (int i = arr.size() - 1; i >= 0; i--) {
                suffix += arr[i];
                maxSuffix = max(maxSuffix, suffix);
            }

            long long ans = maxSuffix +
                            (k - 2LL) * totalSum +
                            maxPrefix;

            best = max(best, ans);
        }

        return best % MOD;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2};
    int k = 3;
    cout << "K-Concatenation Max Sum: " << sol.kConcatenationMaxSum(arr, k) << endl;
    return 0;
}
