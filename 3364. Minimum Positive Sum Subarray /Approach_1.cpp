class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();

        // Step 1: Build prefix sum array
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        // Step 2: Initialize minimum
        int minSum = INT_MAX;

        // Step 3: Check every possible subarray
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {

                // Subarray sum from index i to j
                int sum = prefix[j + 1] - prefix[i];

                // Step 4: Check valid length and positive sum range
                int length = j - i + 1;

                if (length >= l && length <= r && sum > 0) {
                    minSum = min(minSum, sum);
                }
            }
        }

        // Step 5: Return answer
        return minSum == INT_MAX ? -1 : minSum;
    }
};