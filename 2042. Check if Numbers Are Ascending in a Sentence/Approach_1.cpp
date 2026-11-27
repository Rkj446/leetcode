class Solution {
public:
    bool areNumbersAscending(string s) {
        int prev = 0, curr = 0;

        for (char c : s) {
            if (isdigit(c)) {
                curr = curr * 10 + (c - '0');
            } 
            else if (curr > 0) {
                if (curr <= prev) return false;
                prev = curr;
                curr = 0;
            }
        }

        if (curr > 0 && curr <= prev) return false;

        return true;
    }
};