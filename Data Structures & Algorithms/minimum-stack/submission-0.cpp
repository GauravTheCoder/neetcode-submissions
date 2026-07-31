/*
Two Stacks Algorithm
1. Maintain two stacks:
- stack → stores all pushed values.
- minStack → stores the minimum so far at each level.
2. On push(val):
- Push val onto stack.
- Compute the new minimum (between val and the current minimum on minStack).
- Push this minimum onto minStack.
3. On pop():
- Pop from both stack and minStack to keep them aligned.
4. On top():
- Return the top of stack.
5. On getMin():
- Return the top of minStack, which is the current minimum.
*/

class MinStack {
private:
    std::stack<int> stack, minStack;
public:
    MinStack() {}
    
    void push(int val) {
        stack.push(val);
        val = std::min(val, minStack.empty() ? val : minStack.top());
        minStack.push(val);
    }
    
    void pop() {
        stack.pop();
        minStack.pop();
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
