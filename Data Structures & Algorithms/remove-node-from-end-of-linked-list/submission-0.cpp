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
1. Recursively go to the end of the list.
2. As recursion unwinds, decrement n each time you return.
3. When n becomes 0, this is the node to delete → return its next node.
4. Otherwise, return the current node to rebuild the list.
5. The head of the resulting rebuilt list is the final answer.
*/

class Solution {
public:
    ListNode* rec(ListNode* head, int& n) {
        if (!head) {
            return NULL;
        }

        head -> next = rec(head -> next, n);
        n--;
        if (n == 0) {
            return head -> next;
        }
        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return rec(head, n);
    }
};
