class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n, 1);
        
        // Step 1: Calculate prefix products and store them in output array
        // output[i] will contain the product of all elements to the left of i
        for (int i = 1; i < n; ++i) {
            output[i] = output[i - 1] * nums[i - 1];
        }
        
        // Step 2: Calculate suffix products on the fly and multiply with prefix
        int suffix_product = 1;
        for (int i = n - 1; i >= 0; --i) {
            output[i] = output[i] * suffix_product;
            suffix_product *= nums[i];
        }
        
        return output;
    }
};