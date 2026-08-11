/*
Optimal Algorithm
1. Initialize an empty stack.
2. For each asteroid, if it's positive or the stack is empty or the top is negative, push it.
3. If the asteroid is negative and the top is positive, compare sizes:
- If the top is smaller, pop it and continue checking.
- If they're equal, pop the top and discard the current asteroid.
- If the top is larger, discard the current asteroid.
4. After processing all asteroids, the stack contains the survivors.
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;
        for (int& a : asteroids) {
            while (!stack.empty() && a < 0 && stack.back() > 0) {
                int diff = a + stack.back();
                if (diff < 0) {
                    stack.pop_back();
                } else if (diff > 0) {
                    a = 0;
                } else {
                    a = 0;
                    stack.pop_back();
                }
            }
            if (a != 0) {
                stack.push_back(a);
            }
        }
        return stack;
    }
};