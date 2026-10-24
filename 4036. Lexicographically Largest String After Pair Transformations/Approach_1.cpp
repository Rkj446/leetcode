class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string> ans;

        for (int x : nums) {
            string s = "";

            while (x > 0) {
                if (x >= (1 << 25)) {
                    s += 'z';
                    x -= (1 << 25);
                } else {
                    int i = 31 - __builtin_clz(x);
                    s += char('a' + i);
                    x -= (1 << i);
                }
            }

            ans.push_back(s);
        }

        return ans;
    }
};