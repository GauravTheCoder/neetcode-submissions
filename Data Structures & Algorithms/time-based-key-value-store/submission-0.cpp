/*
Optimal Algorithm
1. Use a dictionary:
- key → list of [value, timestamp]
- Timestamps for each key are stored in sorted order (because they arrive in increasing order).
2. set(key, value, timestamp):
- Append [value, timestamp] to the key’s list.
3. get(key, timestamp):
- If the key does not exist, return "".
- Let arr be the list of [value, timestamp] pairs.
- Perform binary search on timestamps to find the rightmost timestamp t ≤ timestamp.
- If found, return the corresponding value.
- If not found, return "".
*/

class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> keyStore;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        keyStore[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto& values = keyStore[key];
        int left = 0, right = values.size() - 1;
        string result = "";

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (values[mid].first <= timestamp) {
                result = values[mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};
