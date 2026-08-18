/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 Algorithm
1. If left is 1, call the helper function reverseList to reverse the first right nodes.
2. Otherwise, recurse with head.next and decremented left and right values, then attach the result to head.next.
3. The helper function reverseList reverses n nodes starting from the given node:
- Base case: when n is 1, save the successor (next node) and return current node.
- Recurse on the next node with n - 1.
- After recursion, make the next node point back to current and set current's next to the saved successor.
4. Return the new head of the reversed portion.
 */

class Solution {
private:
    pair<ListNode*, ListNode*> reverseList(ListNode* node, int n)
    {
        if (n == 1) {
            return {node, node->next};
        }
        auto result = reverseList(node->next, n - 1);
        node->next->next = node;
        node->next = result.second;
        return {result.first, node->next};
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == 1) {
            return reverseList(head, right).first;
        }
        head->next = reverseBetween(head->next, left - 1, right - 1);
        return head;
    }
};