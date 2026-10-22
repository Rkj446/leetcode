
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {

        // Step 1: Total operations available for both arrays.
        long long k = (long long)k1 + k2;

        int n = nums1.size();

        // Step 2: freq[d] stores how many times
        // the absolute difference d occurs.
        vector<int> freq(100001, 0);

        int maxDiff = 0;

        // Calculate the absolute difference at each index.
        for (int i = 0; i < n; i++) {
            int diff = abs(nums1[i] - nums2[i]);

            // Count the occurrence of this difference.
            freq[diff]++;

            // Keep track of the largest difference.
            maxDiff = max(maxDiff, diff);
        }

        // Step 3: Reduce the largest differences first.
        // This greedy approach minimizes the sum of squares.
        for (int d = maxDiff; d > 0 && k > 0; d--) {

            // Number of differences currently equal to d.
            int count = freq[d];

            // Reduce as many as possible, without exceeding k.
            int reduce = (int)min(k, (long long)count);

            // Move these differences from d to d - 1.
            freq[d] -= reduce;
            freq[d - 1] += reduce;

            // Update the remaining operations.
            k -= reduce;
        }

        // Step 4: Calculate the final sum of squared differences.
        long long ans = 0;

        for (int d = 1; d <= maxDiff; d++) {

            // Each difference d contributes d * d.
            // Multiply by its frequency.
            ans += 1LL * d * d * freq[d];
        }

        // Step 5: Return the minimum sum.
        return ans;
    }
};
