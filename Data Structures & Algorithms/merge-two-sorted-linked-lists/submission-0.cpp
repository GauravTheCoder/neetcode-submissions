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
1. If one list is empty, return the other list — nothing left to merge.
2. Compare the head values of list1 and list2:
- If list1.val <= list2.val:
- Set list1.next to the merged result of the remaining nodes.
- Return list1 as the current head.
- Otherwise:
- Set list2.next to the merged result of the remaining nodes.
- Return list2 as the current head.
3. The recursion continues until both lists are fully merged.
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) {
            return list2;
        }
        if (!list2) {
            return list1;
        }
        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};
