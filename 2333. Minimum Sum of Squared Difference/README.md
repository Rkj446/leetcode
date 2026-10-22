# 2333. Minimum Sum of Squared Difference

### Difficulty: Medium

## Description
You are given two positive 0-indexed integer arrays nums1 and nums2, both of length n.

The sum of squared difference of arrays nums1 and nums2 is defined as the sum of (nums1[i] - nums2[i])2 for each 0 <= i < n.

You are also given two positive integers k1 and k2. You can modify any of the elements of nums1 by +1 or -1 at most k1 times. Similarly, you can modify any of the elements of nums2 by +1 or -1 at most k2 times.

Return the minimum sum of squared difference after modifying array nums1 at most k1 times and modifying array nums2 at most k2 times.

Note: You are allowed to modify the array elements to become negative integers.

 
Example 1:


Input: nums1 = [1,2,3,4], nums2 = [2,10,20,19], k1 = 0, k2 = 0
Output: 579
Explanation: The elements in nums1 and nums2 cannot be modified because k1 = 0 and k2 = 0. 
The sum of square difference will be: (1 - 2)2 + (2 - 10)2 + (3 - 20)2 + (4 - 19)2 = 579.


Example 2:


Input: nums1 = [1,4,10,12], nums2 = [5,8,6,9], k1 = 1, k2 = 1
Output: 43
Explanation: One way to obtain the minimum sum of square difference is: 
- Increase nums1[0] once.
- Increase nums2[2] once.
The minimum of the sum of square difference will be: 
(2 - 5)2 + (4 - 8)2 + (10 - 7)2 + (12 - 9)2 = 43.
Note that, there are other ways to obtain the minimum of the sum of square difference, but there is no way to obtain a sum smaller than 43.

 
Constraints:


	n == nums1.length == nums2.length
	1 <= n <= 105
	0 <= nums1[i], nums2[i] <= 105
	0 <= k1, k2 <= 109

## Submission Details
- **Status**: Accepted
- **Runtime**: 18
- **Memory**: 136288000
- **Language**: cpp

## Code
```cpp

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

```
