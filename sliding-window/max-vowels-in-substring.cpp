// LeetCode 1456 - Maximum Number of Vowels in a Substring of Given Length
// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
// Approach: Fixed-size Sliding Window
// Time: O(n) | Space: O(1)

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
 int check (char &word){
  
  if(word == 'i' ||
   word == 'e' ||
   word == 'a' ||
   word == 'o' ||
   word == 'u'){
            return true;
        }
        return false;
   }
    int maxVowels(string s, int k) {

        int high=k-1;
        int low=0;
        int res=0;
        int count=0;
        int n=s.size();
        for(int i=low;i<=high;i++){//first window
            if(check(s[i])){
                count++;
            }
        }
           res=count;
          while(high<n){
            if(check(s[low])){
                count--;
            }
            low++;
            if(high==n)
            break;
          
           high++;
            if(check(s[high])){
                count++;
            }
            
            res=max(res,count);
          
          
        }
        return res;
     
    }
};

int main() {
    Solution sol;

    // Example 1: s = "abciiidef", k = 3 -> Output: 3
    cout << "Example 1: " << sol.maxVowels("abciiidef", 3) << endl;

    // Example 2: s = "aeiou", k = 2 -> Output: 2
    cout << "Example 2: " << sol.maxVowels("aeiou", 2) << endl;

    // Example 3: s = "leetcode", k = 3 -> Output: 2
    cout << "Example 3: " << sol.maxVowels("leetcode", 3) << endl;

    return 0;
}
