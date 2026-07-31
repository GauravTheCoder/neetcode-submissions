/*
Queue Of Queues Algorithm
1. Initialize q as null (empty stack).
2. push(x): Create a new queue/node containing x as the first element and the old q as the second element. Update q to point to this new structure.
3. pop(): Extract the first element (the value), update q to point to the second element (the rest of the stack), and return the value.
4. top(): Return the first element of q without modifying anything.
5. empty(): Return true if q is null.
*/

class MyStack {
private:
    struct Node {
        int val;
        shared_ptr<Node> next;
        Node(int v, shared_ptr<Node> n) : val(v), next(n) {}
    };
    shared_ptr<Node> q;
public:
    MyStack() : q(nullptr) {}
    
    void push(int x) {
        q = make_shared<Node>(x, q);
    }
    
    int pop() {
        if (!q) return -1;
        int top = q->val;
        q = q->next;
        return top;
    }
    
    int top() {
        if (!q) return -1;
        return q->val;
    }
    
    bool empty() {
        return q == nullptr;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */