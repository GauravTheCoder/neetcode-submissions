/*
Optimal Algorithm
1. Pair each car's position with its speed.
2. Sort the cars in descending order of position (closest to target first).
3. For each car:
- Compute the time it takes to reach the target.
- Push this time onto a stack.
- If the new car’s time is less than or equal to the time before it, it catches up and merges with that fleet → pop it from the stack.
4. The number of remaining times in the stack equals the number of fleets.
5. Return the stack size.
*/

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pair;
        for (int i = 0; i < position.size(); i++) {
            pair.push_back({position[i], speed[i]});
        }
        sort(pair.rbegin(), pair.rend());
        vector<double> stack;
        for (auto& p : pair) {
            stack.push_back((double)(target - p.first) / p.second);
            if (stack.size() >= 2 &&
                stack.back() <= stack[stack.size() - 2])
            {
                stack.pop_back();
            }
        }
        return stack.size();
    }
};
