// Longest Substring Without Repeating Characters
// LeetCode #3
// Given a string s, find the length of the longest substring without repeating characters.
// Approach: Sliding window with a frequency map. Expand the window by moving `high`,
//           and shrink from `low` whenever the window contains duplicates
//           (detected when map size < window size).

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int high = 0;
        int low = 0;
        int res = 0;
        unordered_map<char, int> f;
        int n = s.size();
        for (high = 0; high < n; high++) {
            f[s[high]]++;
            int k = high - low + 1;
            while (f.size() < k) {
                f[s[low]]--;
                if (f[s[low]] == 0) {
                    f.erase(s[low]);
                }
                low++;
                k = high - low + 1;
            }
            int len = high - low + 1;
            res = max(len, res);
        }
        return res;
    }
};

int main() {
    Solution sol;

    string s1 = "abcabcbb";
    cout << "Input: \"" << s1 << "\"" << endl;
    cout << "Output: " << sol.lengthOfLongestSubstring(s1) << endl;
    // Expected: 3 ("abc")

    string s2 = "bbbbb";
    cout << "\nInput: \"" << s2 << "\"" << endl;
    cout << "Output: " << sol.lengthOfLongestSubstring(s2) << endl;
    // Expected: 1 ("b")

    string s3 = "pwwkew";
    cout << "\nInput: \"" << s3 << "\"" << endl;
    cout << "Output: " << sol.lengthOfLongestSubstring(s3) << endl;
    // Expected: 3 ("wke")

    return 0;
}
