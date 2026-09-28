// Problem: Longest K Unique Characters Substring
// Difficulty: Medium
// Topic: Sliding Window

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    int longestKSubstr(string& s, int k) {

        int low = 0;
        int res = -1;
        int n = s.size();

        unordered_map<char, int> f;

        for(int high = 0; high < n; high++) {

            f[s[high]]++;

            while(f.size() > k) {

                f[s[low]]--;

                if(f[s[low]] == 0) {
                    f.erase(s[low]);
                }

                low++;
            }

            if(f.size() == k) {
                int len = high - low + 1;
                res = max(res, len);
            }
        }

        return res;
    }
};

int main() {
    Solution solution;

    string s1 = "aabacbebebe";
    int k1 = 3;
    cout << "Input: s = \"" << s1 << "\", k = " << k1 << '\n';
    cout << "Output: " << solution.longestKSubstr(s1, k1) << '\n';

    string s2 = "aaaa";
    int k2 = 2;
    cout << "\nInput: s = \"" << s2 << "\", k = " << k2 << '\n';
    cout << "Output: " << solution.longestKSubstr(s2, k2) << '\n';

    return 0;
}
