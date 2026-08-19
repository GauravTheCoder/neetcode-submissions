/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 Recursive Algorithm
1. Start at the given head and try to move forward k nodes.
- Count how many nodes are available using counter group.
- If fewer than k, return the current head unchanged.
2. If exactly k nodes exist:
- Recursively call the function on the node after these k nodes (cur).
- This returns the head of the reversed remainder.
- Reverse the current group of k nodes:
- For each of the k nodes:
- Temporarily store head.next in tmp
- Point head.next to the result of the recursive call
- Move forward
- After reversing all k nodes, return the new head of this group.
3. The recursion ensures each segment is reversed and correctly connected to the next processed segment.
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        int group = 0;
        while (cur != nullptr && group < k) {
            cur = cur->next;
            group++;
        }

        if (group == k) {
            cur = reverseKGroup(cur, k);
            while (group-- > 0) {
                ListNode* tmp = head->next;
                head->next = cur;
                cur = head;
                head = tmp;
            }
            head = cur;
        }
        return head;
    }
};
