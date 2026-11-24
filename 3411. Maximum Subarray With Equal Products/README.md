# 3411. Maximum Subarray With Equal Products

### Difficulty: Easy

## Description
You are given an array of positive integers nums.

An array arr is called product equivalent if prod(arr) == lcm(arr) * gcd(arr), where:


	prod(arr) is the product of all elements of arr.
	gcd(arr) is the GCD of all elements of arr.
	lcm(arr) is the LCM of all elements of arr.


Return the length of the longest product equivalent subarray of nums.

 
Example 1:


Input: nums = [1,2,1,2,1,1,1]

Output: 5

Explanation: 

The longest product equivalent subarray is [1, 2, 1, 1, 1], where prod([1, 2, 1, 1, 1]) = 2, gcd([1, 2, 1, 1, 1]) = 1, and lcm([1, 2, 1, 1, 1]) = 2.


Example 2:


Input: nums = [2,3,4,5,6]

Output: 3

Explanation: 

The longest product equivalent subarray is [3, 4, 5].


Example 3:


Input: nums = [1,2,3,1,4,5,1]

Output: 5


 
Constraints:


	2 <= nums.length <= 100
	1 <= nums[i] <= 10

## Submission Details
- **Status**: Accepted
- **Runtime**: 1
- **Memory**: 27984000
- **Language**: cpp

## Code
```cpp
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int ans = min(n, 2);

        for (int right = 0; right < n; right++) {

            // Check whether nums[right] is coprime
            // with every element in the current window.
            while (left < right) {
                bool valid = true;

                for (int i = left; i < right; i++) {
                    if (gcd(nums[i], nums[right]) != 1) {
                        valid = false;
                        break;
                    }
                }

                if (valid) break;

                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
```
