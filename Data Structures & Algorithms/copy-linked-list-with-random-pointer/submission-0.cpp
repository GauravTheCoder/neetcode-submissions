/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
Optimal Algorithm
1. Create all copied nodes
- For each original node A, create a copy A'.
- Store this copy inside A.random.
- Set A'.next = A.random_old.
2. Fix random pointers of copies
- For each original node A, set A'.random = A.random_old.random' (if exists).
3. Extract the copied list and restore original list
- For each original node A:
- Restore A.random = original_random.
- Connect A'.next to the next copied node.
4. Return the head of the copied list (which is head.random).
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }

        Node* l1 = head;
        while (l1) {
            Node* l2 = new Node(l1->val);
            l2->next = l1->random;
            l1->random = l2;
            l1 = l1->next;
        }

        Node* newHead = head->random;

        l1 = head;
        while (l1) {
            Node* l2 = l1->random;
            l2->random = (l2->next != nullptr) ? l2->next->random : nullptr;
            l1 = l1->next;
        }

        l1 = head;
        while (l1) {
            Node* l2 = l1->random;
            l1->random = l2->next;
            l2->next = (l1->next != nullptr) ? l1->next->random : nullptr;
            l1 = l1->next;
        }
        return newHead;
    }
};
