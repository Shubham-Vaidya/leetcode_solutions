class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> res(n,0);
        // res.push_back(0);
        st.push(n-1);
        for(int i = n-2 ; i >= 0; i--){
            int count = 1;
            if(temperatures[i] < temperatures[st.top()]){
                // res.push_back(st.top() - i);
                res[i] = st.top() - i;
                st.push(i);
            }
            else{
                while(!st.empty() && temperatures[i] >= temperatures[st.top()]){
                    st.pop();
                    // count++;
                }
                if(st.empty()){
                    // res.push_back(0);
                    st.push(i);
                    // count = 1;
                }
                else{
                    res[i] = st.top() - i;
                    // res.push_back(st.top() - i);
                    // count = 1;
                    st.push(i);
                } 
            }
        }
        return res;
    }
};