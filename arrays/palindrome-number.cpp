// LeetCode 9 - Palindrome Number
// https://leetcode.com/problems/palindrome-number/
// Approach: Reverse the number and compare
// Time: O(log n) | Space: O(1)

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int check(int n) {
        int rev = 0;
        while(n > 0) {
            int d = n % 10;
            rev = rev * 10 + d;
            n = n / 10;
        }
        return rev;
    }

    bool isPalindrome(int n) {
        if(check(n) == abs(n)) {
            return true;
        }
        else {
            return false;
        }
    }
};

int main() {
    Solution sol;

    // Example 1: 121 -> true
    cout << "Example 1 (121):  " << (sol.isPalindrome(121) ? "true" : "false") << endl;

    // Example 2: -121 -> false
    cout << "Example 2 (-121): " << (sol.isPalindrome(-121) ? "true" : "false") << endl;

    // Example 3: 10 -> false
    cout << "Example 3 (10):   " << (sol.isPalindrome(10) ? "true" : "false") << endl;

    // Example 4: 0 -> true
    cout << "Example 4 (0):    " << (sol.isPalindrome(0) ? "true" : "false") << endl;

    return 0;
}
