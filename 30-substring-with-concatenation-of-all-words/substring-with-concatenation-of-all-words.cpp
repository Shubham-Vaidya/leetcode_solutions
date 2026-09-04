class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;

        int wordSize = words[0].size();
        int wordCount = words.size();
        int totalSize = wordSize * wordCount;

        if (totalSize > s.size()) {
            return result;
        }

        unordered_map<string, int> wordsCount;

        for (string word : words) {
            wordsCount[word]++;
        }

        for (int start = 0; start < wordSize; start++) {

            int left = start;
            int right = start;
            int count = 0;

            unordered_map<string, int> windowCount;

            while (right + wordSize <= s.size()) {

                string word = s.substr(right, wordSize);
                right += wordSize;

                if (wordsCount.find(word) == wordsCount.end()) {
                    windowCount.clear();
                    count = 0;
                    left = right;
                    continue;
                }

                windowCount[word]++;
                count++;

                while (windowCount[word] > wordsCount[word]) {
                    string leftWord = s.substr(left, wordSize);
                    windowCount[leftWord]--;
                    left += wordSize;
                    count--;
                }

                if (count == wordCount) {
                    result.push_back(left);

                    string leftWord = s.substr(left, wordSize);
                    windowCount[leftWord]--;
                    left += wordSize;
                    count--;
                }
            }
        }

        return result;
    }
};