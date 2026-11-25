
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> freq(26, 0);

        // Count frequency of each task
        for (char ch : tasks) {
            freq[ch - 'A']++;
        }

        // Find maximum frequency
        int maxFreq = 0;

        for (int f : freq) {
            maxFreq = max(maxFreq, f);
        }

        // Count tasks having maximum frequency
        int countMax = 0;

        for (int f : freq) {
            if (f == maxFreq) {
                countMax++;
            }
        }

        // Calculate minimum required intervals
        int result = (maxFreq - 1) * (n + 1) + countMax;

        return max((int)tasks.size(), result);
    }
};
