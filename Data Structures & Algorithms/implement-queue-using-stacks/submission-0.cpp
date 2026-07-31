/*
Using Two Stacks (Amortized Complexity) Algorithm
1. For push: Push the element onto s1.
2. For pop: If s2 is empty, transfer all elements from s1 to s2. Then pop from s2.
3. For peek: If s2 is empty, transfer all elements from s1 to s2. Then return the top of s2.
4. For empty: Return true if both s1 and s2 are empty.
*/

class MyQueue {
private:
    stack<int> s1, s2;
public:
    MyQueue() {}
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int result = s2.top();
        s2.pop();
        return result;
    }
    
    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */