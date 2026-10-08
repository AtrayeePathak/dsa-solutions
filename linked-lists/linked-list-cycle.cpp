// LeetCode 141 - Linked List Cycle
// https://leetcode.com/problems/linked-list-cycle/
// Approach: Floyd's Cycle Detection (Tortoise and Hare)
// Time: O(n) | Space: O(1)

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution sol;

    // Example 1: 3 -> 2 -> 0 -> -4 -> (back to 2) — has cycle
    ListNode* head1 = new ListNode(3);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(0);
    head1->next->next->next = new ListNode(-4);
    head1->next->next->next->next = head1->next; // cycle at node 2

    cout << "Example 1 (has cycle): " << (sol.hasCycle(head1) ? "true" : "false") << endl;

    // Example 2: 1 -> 2 -> (back to 1) — has cycle
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = head2; // cycle at node 1

    cout << "Example 2 (has cycle): " << (sol.hasCycle(head2) ? "true" : "false") << endl;

    // Example 3: 1 -> nullptr — no cycle
    ListNode* head3 = new ListNode(1);

    cout << "Example 3 (no cycle):  " << (sol.hasCycle(head3) ? "true" : "false") << endl;

    // Cleanup (only non-cyclic list can be safely deleted)
    delete head3;

    return 0;
}
