/*
Optimal Algorithm
1. Initialize a dummy node left, set right = left, and set space = k.
2. For enQueue(value): If full, return false. Create a new node. If empty, set it as left.next and right. Otherwise, link it after right and update right. Decrement space and return true.
3. For deQueue(): If empty, return false. Remove left.next by updating left.next to left.next.next. If left.next becomes null, reset right = left. Increment space and return true.
4. For Front(): If empty, return -1. Otherwise, return left.next.val.
5. For Rear(): If empty, return -1. Otherwise, return right.val.
6. For isEmpty(): Return true if left.next is null.
7. For isFull(): Return true if space equals 0.
*/

class MyCircularQueue {
private:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int v) : val(v), next(nullptr) {}
    };

    int space;
    ListNode* left;
    ListNode* right;
public:
    MyCircularQueue(int k) {
        space = k;
        left = new ListNode(0);
        right = left;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;

        ListNode* cur = new ListNode(value);
        if (isEmpty()) {
            left->next = cur;
            right = cur;
        } else {
            right->next = cur;
            right = cur;
        }

        space--;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;

        ListNode* tmp = left->next;
        left->next = left->next->next;
        delete tmp;
        if (!left->next) {
            right = left;
        }

        space++;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : left->next->val;
    }
    
    int Rear() {
        return isEmpty() ? -1 : right->val;
    }
    
    bool isEmpty() {
        return left->next == nullptr;
    }
    
    bool isFull() {
        return space == 0;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */