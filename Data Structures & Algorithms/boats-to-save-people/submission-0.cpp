/*
Optimal Solution
1. Sort the array of people's weights in non-decreasing order to easily match the heaviest and lightest individuals.
2. Initialize two pointers: a left pointer at index 0 (representing the lightest person) and a right pointer at the last index (representing the heaviest person).
3. Initialize a counter to keep track of the total number of boats used.
4. Iterate while the left pointer is less than or equal to the right pointer.
5. Check if the sum of weights of the lightest person and the heaviest person is less than or equal to the limit.
6. If the combined weight is within the limit, it means both can share a boat. Advance the left pointer to the right.
7. Regardless of whether they can share or not, the heaviest person must be accommodated on this boat. Move the right pointer to the left.
8. Increment the boat count by one for each iteration of the loop.
9. Return the total boat count when all people have been processed.
*/
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        std::sort(people.begin(), people.end());
        
        int boats{0};
        int left{0};
        int right{static_cast<int>(people.size())-1};
        
        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                left++;
            }
            right--;
            boats++;
        }
        
        return boats;
    }
};