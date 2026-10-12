// Coding Ninjas - Count Of Substrings Consisting Only Of Vowels
// https://www.naukri.com/code360/problems/count-of-substrings-consisting-only-of-vowels_
// Approach: Streak counting — for each consecutive vowel streak, add streak length to count
// Time: O(n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;

int countSubstrings(string &s)
{
    int count = 0;
    int streak = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
            s[i] == 'o' || s[i] == 'u') {
            streak++;
            count += streak;
        }
        else {
            streak = 0;
        }
    }

    return count;
}

int main() {
    // Example 1: "codestudio" -> 6
    // Vowel substrings: {"o", "e", "u", "i", "io", "o"}
    string s1 = "codestudio";
    cout << "Example 1 (codestudio): " << countSubstrings(s1) << endl;

    // Example 2: "wxyz" -> 0
    string s2 = "wxyz";
    cout << "Example 2 (wxyz): " << countSubstrings(s2) << endl;

    // Example 3: "codingninjas" -> 4
    string s3 = "codingninjas";
    cout << "Example 3 (codingninjas): " << countSubstrings(s3) << endl;

    // Example 4: "artycg" -> 1
    string s4 = "artycg";
    cout << "Example 4 (artycg): " << countSubstrings(s4) << endl;

    return 0;
}
