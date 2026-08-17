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
Recursive Algorithm
1. If the list is empty, return null.
2. Recursively call the function on head.next to reverse the rest of the list.
3. After the recursive call returns:
- Make head.next.next = head so the next node points back to the current node.
4. Set head.next = null to avoid cycles.
5. Return the new head returned by the deepest recursive call.
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        ListNode* newHead = head;
        if (head->next) {
            newHead = reverseList(head->next);
            head->next->next = head;
        }
        head->next = nullptr;

        return newHead;
    }
};
