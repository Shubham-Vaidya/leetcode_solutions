
class Solution {
public:
    string removeDuplicates(string s) {
        vector<char> res;
        stack<char> st;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (st.empty()) 
            {
                st.push(s[i]);
                res.push_back(s[i]);
            }
            else {
                char c = s[i];

                if (st.top() == c) {
                    st.pop();
                    res.pop_back();
                }
                else {
                    st.push(s[i]);
                    res.push_back(s[i]);
                }
            }
        }

        return string(res.begin(), res.end());
    }
};
