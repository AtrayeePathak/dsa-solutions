// Minimum Window Substring
// LeetCode #76
// Given two strings s and t, return the minimum window substring of s such that
// every character in t (including duplicates) is included in the window.
// If there is no such substring, return the empty string "".
// Approach: Sliding window with two frequency arrays (have/needed).
//           Expand by moving `high`, and shrink from `low` whenever the window
//           satisfies the requirement (checked via the `sahi` helper).

#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    bool sahi(vector<int>& have, vector<int> needed) {
        for (int i = 0; i < 256; i++) {
            if (have[i] < needed[i]) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        vector<int> needed(256, 0);
        vector<int> have(256, 0);

        for (int i = 0; i < t.size(); i++) {
            needed[t[i]]++;
        }

        int high = 0;
        int low = 0;
        int res = INT_MAX;
        int start = 0;

        for (high = 0; high < s.size(); high++) {
            have[s[high]]++;

            while (sahi(have, needed)) {
                int len = high - low + 1;
                if (res > len) {
                    res = len;
                    start = low;
                }
                have[s[low]]--;
                low++;
            }
        }

        if (res == INT_MAX)
            return "";

        return s.substr(start, res);
    }
};

int main() {
    Solution sol;

    string s1 = "ADOBECODEBANC", t1 = "ABC";
    cout << "Input: s = \"" << s1 << "\", t = \"" << t1 << "\"" << endl;
    cout << "Output: \"" << sol.minWindow(s1, t1) << "\"" << endl;
    // Expected: "BANC"

    string s2 = "a", t2 = "a";
    cout << "\nInput: s = \"" << s2 << "\", t = \"" << t2 << "\"" << endl;
    cout << "Output: \"" << sol.minWindow(s2, t2) << "\"" << endl;
    // Expected: "a"

    string s3 = "a", t3 = "aa";
    cout << "\nInput: s = \"" << s3 << "\", t = \"" << t3 << "\"" << endl;
    cout << "Output: \"" << sol.minWindow(s3, t3) << "\"" << endl;
    // Expected: ""

    return 0;
}
