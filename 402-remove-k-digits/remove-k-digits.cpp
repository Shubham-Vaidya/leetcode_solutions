class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        stack<char> st;
        st.push(num[0]);
        for(int i = 1 ; i < n ; i++){
            while(!st.empty() &&st.top() > num[i]  && k>0 ){
                 st.pop();
                 k--;
            }
            st.push(num[i]);
        }
        while(k > 0 && !st.empty())
        {
            st.pop();
            k--;
        }
        string res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        int i = 0;
        while(i < res.size() && res[i] == '0')
        {
            i++;
        }
        res = res.substr(i);
        if(res.empty()) return "0";
        return res;
    }
};