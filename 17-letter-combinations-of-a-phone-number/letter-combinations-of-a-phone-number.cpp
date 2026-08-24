class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};
        
        vector<string> keypad = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> result = {""};

        for(char digit : digits){
            vector<string> next;

            string letters = keypad[digit - '0'];

            for(string str : result){
                for(char ch : letters){
                    next.push_back(str + ch);
                }
            }
            result = next;
        }
            return result;
    }
};