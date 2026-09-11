#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countTriplets(int sum, vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int answer = 0;
        int n = static_cast<int>(arr.size());

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int totalSum = arr[i] + arr[left] + arr[right];

                if (totalSum >= sum) {
                    right--;
                } else {
                    answer += right - left;
                    left++;
                }
            }
        }

        return answer;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int& value : arr) {
        cin >> value;
    }

    int sum;
    cin >> sum;

    Solution solution;
    cout << solution.countTriplets(sum, arr) << '\n';

    return 0;
}
