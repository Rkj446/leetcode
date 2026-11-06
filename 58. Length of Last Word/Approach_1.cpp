
class Solution {
public:
    int lengthOfLastWord(string s) {

        int i = s.size() - 1;

        // Step 1: Skip trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Step 2: Count characters of last word
        int count = 0;

        while (i >= 0 && s[i] != ' ') {
            count++;
            i--;
        }

        return count;
    }
};
