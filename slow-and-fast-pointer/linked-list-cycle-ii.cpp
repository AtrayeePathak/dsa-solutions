// LeetCode 142 - Linked List Cycle II
// https://leetcode.com/problems/linked-list-cycle-ii/
// Approach: Floyd's Cycle Detection (find cycle start node)
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
    ListNode *detectCycle(ListNode *head) {
         ListNode * slow=head;
          ListNode * fast=head;

          while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }

        }
        return nullptr;
    }
};

int main() {
    Solution sol;

    // Example 1: 3 -> 2 -> 0 -> -4 -> (back to 2) — cycle starts at node 2
    ListNode* head1 = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    head1->next = node2;
    head1->next->next = new ListNode(0);
    head1->next->next->next = new ListNode(-4);
    head1->next->next->next->next = node2; // cycle

    ListNode* result1 = sol.detectCycle(head1);
    cout << "Example 1 (cycle at node): " << (result1 ? to_string(result1->val) : "no cycle") << endl;

    // Example 2: 1 -> 2 -> (back to 1) — cycle starts at node 1
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = head2; // cycle

    ListNode* result2 = sol.detectCycle(head2);
    cout << "Example 2 (cycle at node): " << (result2 ? to_string(result2->val) : "no cycle") << endl;

    // Example 3: 1 -> nullptr — no cycle
    ListNode* head3 = new ListNode(1);

    ListNode* result3 = sol.detectCycle(head3);
    cout << "Example 3 (no cycle):     " << (result3 ? to_string(result3->val) : "no cycle") << endl;

    // Cleanup (only non-cyclic)
    delete head3;

    return 0;
}
