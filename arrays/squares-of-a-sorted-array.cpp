#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;

        for (int value : nums) {
            if (value > 0) {
                pos.push_back(value);
            } else {
                neg.push_back(value);
            }
        }

        if (pos.empty()) {
            for (int& value : neg) {
                value *= value;
            }
            reverse(neg.begin(), neg.end());
            return neg;
        }

        if (neg.empty()) {
            for (int& value : pos) {
                value *= value;
            }
            return pos;
        }

        for (int& value : pos) {
            value *= value;
        }
        for (int& value : neg) {
            value *= value;
        }
        reverse(neg.begin(), neg.end());

        int i = 0;
        int j = 0;
        int index = 0;
        vector<int> result(pos.size() + neg.size());

        while (i < static_cast<int>(pos.size()) && j < static_cast<int>(neg.size())) {
            if (neg[j] <= pos[i]) {
                result[index++] = neg[j++];
            } else {
                result[index++] = pos[i++];
            }
        }

        while (i < static_cast<int>(pos.size())) {
            result[index++] = pos[i++];
        }

        while (j < static_cast<int>(neg.size())) {
            result[index++] = neg[j++];
        }

        return result;
    }
};

int main() {
    int size;
    cin >> size;

    vector<int> nums(size);
    for (int& value : nums) {
        cin >> value;
    }

    Solution solution;
    vector<int> result = solution.sortedSquares(nums);

    for (int value : result) {
        cout << value << " ";
    }
    cout << '\n';

    return 0;
}
