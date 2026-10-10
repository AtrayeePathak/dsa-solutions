// LeetCode 876 - Middle of the Linked List
// https://leetcode.com/problems/middle-of-the-linked-list/
// Approach: Slow and Fast Pointer
// Time: O(n) | Space: O(1)

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};

int main() {
    Solution sol;

    // Example 1: 1 -> 2 -> 3 -> 4 -> 5 -> Output: 3
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);

    ListNode* mid1 = sol.middleNode(head1);
    cout << "Example 1 (odd length): " << mid1->val << endl;

    // Example 2: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> Output: 4 (second middle)
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);
    head2->next->next->next->next->next = new ListNode(6);

    ListNode* mid2 = sol.middleNode(head2);
    cout << "Example 2 (even length): " << mid2->val << endl;

    // Example 3: 1 -> Output: 1
    ListNode* head3 = new ListNode(1);
    ListNode* mid3 = sol.middleNode(head3);
    cout << "Example 3 (single node): " << mid3->val << endl;

    return 0;
}
