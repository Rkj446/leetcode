class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        return min({
            nums[n - 1] - nums[2],   // change 2 smallest
            nums[n - 2] - nums[1],   // change 1 smallest & 1 largest
            nums[n - 3] - nums[0]    // change 2 largest
        });
    }
};