class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // if (p.size() > s.size()) {
        //     return false;
        // }

        vector<int> pCount(26, 0);
        vector<int> windowCount(26, 0);
        vector<int> result;
        for (char c : p) {
            pCount[c - 'a']++;
        }

        int left = 0;

        for (int right = 0; right < s.size(); right++) {
            windowCount[s[right] - 'a']++;

            if (right - left + 1 > p.size()) {
                windowCount[s[left] - 'a']--;
                left++;
            }

            if (pCount == windowCount) {
                result.push_back(left);
            }
        }

        return result;
    }
};