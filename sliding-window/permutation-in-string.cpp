// 567. Permutation in String
// https://leetcode.com/problems/permutation-in-string/

#include <string>
#include <vector>
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

    bool checkInclusion(string s1, string s2) {
        vector<int> needed(256, 0);
        vector<int> have(256, 0);
        for (int i = 0; i < s1.size(); i++) {
            needed[s1[i]]++;
        }
        int high = 0;
        int low = 0;
        for (high = 0; high < s2.size(); high++) {
            have[s2[high]]++;
            if (s1.size() > s2.size()) {
                return false;
            }

            if (high - low + 1 > s1.size()) {
                have[s2[low]]--;
                low++;
            }
            if (high - low + 1 == s1.size() && sahi(have, needed)) {
                return true;
            }
        }
        return false;
    }
};

#include <iostream>
int main() {
    Solution sol;
    string s1 = "ab", s2 = "eidbaooo";
    cout << boolalpha << sol.checkInclusion(s1, s2) << endl; // Output: true

    s1 = "ab"; s2 = "eidboaoo";
    cout << boolalpha << sol.checkInclusion(s1, s2) << endl; // Output: false
    return 0;
}
