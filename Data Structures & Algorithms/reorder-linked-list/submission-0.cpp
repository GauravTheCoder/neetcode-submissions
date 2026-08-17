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
1. Define a recursive function rec(root, cur):
- cur moves to the end of the list via recursion.
- root marks the current front node during unwinding.
2. In the base case:
- If cur is None, return the front pointer (root).
3. Recursively call rec on cur.next to reach the tail.
4. During unwinding:
- If root meets or crosses cur, set cur.next = None to finish and stop further links.
- Otherwise:
- Temporarily save root.next in tmp.
- Link root.next → cur.
- Link cur.next → tmp.
5. Return the next node (tmp) as the updated front pointer.
6. Start recursion with rec(head, head.next).
This reorders the list in place without extra storage.
*/

class Solution {
public:
    void reorderList(ListNode* head) {
        head = rec(head, head->next);
    }
    private:
    ListNode* rec(ListNode* root, ListNode* cur) {
        if (cur == nullptr) {
            return root;
        }

        root = rec(root, cur->next);
        if (root == nullptr) {
            return nullptr;
        }

        ListNode* tmp = nullptr;
        if (root == cur || root->next == cur) {
            cur->next = nullptr;
        } else {
            tmp = root->next;
            root->next = cur;
            cur->next = tmp;
        }

        return tmp;
    }
};
