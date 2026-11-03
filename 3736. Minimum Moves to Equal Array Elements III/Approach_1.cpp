class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max= *max_element(nums.begin(),nums.end());
        int ans=0;

        for(auto& a : nums){
            ans+= max-a;
        }
        return ans;
    }
};
/*class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        return mx * nums.size() -
               accumulate(nums.begin(), nums.end(), 0);
    }
};*/