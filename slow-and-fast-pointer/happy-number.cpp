// LeetCode 202 - Happy Number
// https://leetcode.com/problems/happy-number/
// Approach: Floyd's Cycle Detection (Tortoise and Hare)
// Time: O(log n) | Space: O(1)

#include <iostream>
using namespace std;

class Solution {
public:
    int fun(int n) {
        int sum = 0;
        while(n > 0) {
            int d = n % 10;
            sum = sum + d * d;
            n = n / 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        while(fast != 1) {
            slow = fun(slow);
            fast = fun(fast);
            fast = fun(fast);
            if(slow == fast and slow != 1) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    // Example 1: 19 -> true (1² + 9² = 82 -> ... -> 1)
    cout << "Example 1 (19): " << (sol.isHappy(19) ? "true" : "false") << endl;

    // Example 2: 2 -> false (enters a cycle)
    cout << "Example 2 (2):  " << (sol.isHappy(2) ? "true" : "false") << endl;

    // Example 3: 7 -> true
    cout << "Example 3 (7):  " << (sol.isHappy(7) ? "true" : "false") << endl;

    return 0;
}
