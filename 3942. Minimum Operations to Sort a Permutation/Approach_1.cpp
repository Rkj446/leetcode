class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int zero = find(nums.begin(), nums.end(), 0) - nums.begin();

        bool inc = true, dec = true;

        for (int i = 0; i < n; i++) {
            int next = (i + 1) % n;

            if (nums[next] != (nums[i] + 1) % n)
                inc = false;

            if (nums[i] != (nums[next] + 1) % n)
                dec = false;
        }

        if (inc)
            return min(zero, n - zero + 2);

        if (dec)
            return min(zero + 2, n - zero);

        return -1;
    }
};