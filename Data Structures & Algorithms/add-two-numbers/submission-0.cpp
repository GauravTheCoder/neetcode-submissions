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
1. Define a recursive function add(l1, l2, carry):
- If l1, l2 are both None and carry is 0, return None.
- Extract:
- v1 = l1.val if l1 exists, else 0
- v2 = l2.val if l2 exists, else 0
- Compute:
- total = v1 + v2 + carry
- carry, digit = divmod(total, 10)
- Recursively compute the next node using:
- l1.next if exists
- l2.next if exists
- updated carry
- Return a node with value digit whose next is the recursive result.
2. In addTwoNumbers, call:
- return add(l1, l2, 0)
 */

class Solution {
public:
    ListNode* add(ListNode* l1, ListNode* l2, int carry) {
        if (!l1 && !l2 && carry == 0) {
            return nullptr;
        }

        int v1 = 0;
        int v2 = 0;
        if (l1) {
            v1 = l1->val;
        }
        if (l2) {
            v2 = l2->val;
        }

        int sum = v1 + v2 + carry;
        int newCarry = sum / 10;
        int nodeValue = sum % 10;

        ListNode* nextNode = add(
            (l1 ? l1->next : nullptr),
            (l2 ? l2->next : nullptr),
            newCarry
        );

        return new ListNode(nodeValue, nextNode);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1, l2, 0);
    }
};
