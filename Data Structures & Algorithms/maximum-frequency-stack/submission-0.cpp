/*
Optimal Algorithm
1. Initialize a frequency hash map cnt and a list stacks with an empty placeholder at index 0 (since frequencies start at 1).
2. For push(val): increment the value's count. If this count equals the current length of stacks, append a new empty stack. Push the value onto the stack at index equal to its frequency.
3. For pop(): pop from the last stack in the list, decrement that value's frequency. If the last stack becomes empty, remove it from the list. Return the popped value.
*/

class FreqStack {
public:
unordered_map<int, int> cnt;
vector<stack<int>> stacks;
    FreqStack() {
        stacks.push_back(stack<int>());
    }
    
    void push(int val) {
        int valCnt = ++cnt[val];
        if (valCnt == stacks.size()) {
            stacks.push_back(stack<int>());
        }
        stacks[valCnt].push(val);
    }
    
    int pop() {
        stack<int>& topStack = stacks.back();
        int res = topStack.top();
        topStack.pop();
        if (topStack.empty()) {
            stacks.pop_back();
        }
        cnt[res]--;
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */