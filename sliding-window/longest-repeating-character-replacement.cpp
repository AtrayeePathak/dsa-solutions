#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:

    int find(vector<int> a) {
        int maxc = -1;
        for (int i = 0; i < 256; i++) {
            maxc = max(maxc, a[i]);
        }
        return maxc;
    }

    int characterReplacement(string s, int k) {
        int high = 0;
        int low = 0;
        int res = 0;
        int n = s.size();
        vector<int> f(256, 0);

        for (high = 0; high < n; high++) {
            f[s[high]]++;
            int len = high - low + 1;
            int maxcnt = find(f);
            int diff = len - maxcnt;

            while (diff > k) {
                f[s[low]]--;
                low++;
                len = high - low + 1;
                maxcnt = find(f);
                diff = len - maxcnt;
            }

            len = high - low + 1;
            res = max(res, len);
        }
        return res;
    }
};

#include <iostream>
int main() {
    Solution sol;
    string s = "AABABBA";
    int k = 1;
    cout << sol.characterReplacement(s, k) << endl;
    return 0;
}
