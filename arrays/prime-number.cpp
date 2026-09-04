 #include <iostream>
using namespace std;

class Solution {
  public:
    bool isPrime(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                count++;
            }
        }

        if (count == 2) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    int n;
    cin >> n;

    Solution solution;
    cout << solution.isPrime(n);

    return 0;
}