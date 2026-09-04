class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> tCount(128, 0);
        vector<int> windowCount(128, 0);

        for (char c : t) {
            tCount[c]++;
        }

        int left = 0;
        int required = t.size();
        int minLength = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {

            windowCount[s[right]]++;

            if (windowCount[s[right]] <= tCount[s[right]]) {
                required--;
            }

            while (required == 0) {

                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    start = left;
                }

                windowCount[s[left]]--;

                if (windowCount[s[left]] < tCount[s[left]]) {
                    required++;
                }

                left++;
            }
        }

        if (minLength == INT_MAX) {
            return "";
        }

        return s.substr(start, minLength);
    }
};