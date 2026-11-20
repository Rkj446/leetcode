class Solution {
public:
    bool check(vector<int>& nums, long long k) {
        long long ops = 0;

        for (int x : nums) {
            ops += (x + k - 1) / k;   // ceil(x / k)

            if (ops > k * k) {
                return false;
            }
        }

        return ops <= k * k;
    }

    int minimumK(vector<int>& nums) {
        long long l = 1, r = 100000;

        while (l < r) {
            long long mid = l + (r - l) / 2;

            if (check(nums, mid))
                r = mid;
            else
                l = mid + 1;
        }

        return (int)l;
    }
};