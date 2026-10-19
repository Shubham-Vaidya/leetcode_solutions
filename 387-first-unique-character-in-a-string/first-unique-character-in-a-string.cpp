class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mpp;

        // First pass: Count the frequency of every character
        for (int i = 0; i < s.size(); i++) {
            mpp[s[i]]++;
        }

        // Second pass: Find the first character with frequency 1
        for (int i = 0; i < s.size(); i++) {
            if (mpp[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};