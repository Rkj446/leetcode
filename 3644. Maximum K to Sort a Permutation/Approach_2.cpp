class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans = INT_MAX;
        bool sorted = true;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i) {
                ans &= nums[i];
                sorted = false;
            }
        }

        return sorted ? 0 : ans;
    }
};