/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*
Optimal Algorithm
1. Initialize two pointers:
- slow = head
- fast = head
2. Move through the list:
- slow moves one step (slow->next).
- fast moves two steps (fast->next->next).
3. If at any point slow == fast, a cycle exists, return true.
4. If fast reaches the end (null or fast.next is null), no cycle exists, return false.
*/
class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) {
                return true;
            }
        }

        return false;
    }
};
