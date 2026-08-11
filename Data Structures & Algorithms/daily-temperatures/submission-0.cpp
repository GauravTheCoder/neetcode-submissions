/*
Optimal Algorithm
1. Create a result list filled with zeros.
2. Use a stack to store pairs of (temperature, index) for days that haven't found a warmer day yet.
3. Iterate through the temperature list:
- While the stack is not empty and the current temperature is warmer than the top of the stack:
- Pop the top element.
- Compute how many days passed and update the result.
- Push the current day onto the stack.
4. Return the filled result list.
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> stack; // pair: {temp, index}

        for (int i = 0; i < temperatures.size(); i++) {
            int t = temperatures[i];
            while (!stack.empty() && t > stack.top().first) {
                auto pair = stack.top();
                stack.pop();
                res[pair.second] = i - pair.second;
            }
            stack.push({t, i});
        }
        return res;
    }
};
