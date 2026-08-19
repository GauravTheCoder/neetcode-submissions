/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 Optimal Algorithm
1. Base Cases
- If the input list lists is empty, return null.
- Use a recursive function divide(lists, l, r):
- If l > r, return null.
- If l == r, return lists[l] (only one list to return).
2. Divide Step
- Compute mid = (l + r) // 2.
- Recursively compute:
- left = divide(lists, l, mid)
- right = divide(lists, mid + 1, r)
3. Conquer Step (merge two lists)
- Merge left and right using the standard merge two sorted linked lists routine:
- Create a dummy node and use a curr pointer.
- While both lists are non-empty:
- Attach the smaller node to curr.next.
- Move that list's pointer forward.
- Move curr forward.
- Attach any remaining nodes from either list.
- Return the merged list.
4. Final Answer
- Call divide(lists, 0, len(lists) - 1) and return the resulting list.
This approach efficiently merges k sorted linked lists in a structured, recursive way. 
 */
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

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        return divide(lists, 0, lists.size() - 1);
    }

private:
    ListNode* divide(vector<ListNode*>& lists, int l, int r) {
        if (l > r) {
            return nullptr;
        }
        if (l == r) {
            return lists[l];
        }

        int mid = l + (r - l) / 2;
        ListNode* left = divide(lists, l, mid);
        ListNode* right = divide(lists, mid + 1, r);

        return conquer(left, right);
    }

    ListNode* conquer(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        if (l1) {
            curr->next = l1;
        } else {
            curr->next = l2;
        }

        return dummy.next;
    }
};
