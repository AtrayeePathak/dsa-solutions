#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Solution {
public:
    string reverseString(string& s) {
        int left = 0;
        int right = static_cast<int>(s.length()) - 1;

        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }

        return s;
    }
};

int main() {
    string input;
    cin >> input;

    Solution solution;
    cout << solution.reverseString(input) << endl;

    return 0;
}
