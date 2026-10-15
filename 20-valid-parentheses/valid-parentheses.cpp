class Solution {
public:
    bool isValid(string s) 
    {
        int n = s.size();
        stack<char> st;
        if(n == 1)return false;
        if(n == 0)return true;
        for(int i = 0 ; i< n ; i++){
            char c = s[i];
            if(c == '(' || c == '{' || c == '[' ){
                st.push(c);
            }
            if(st.empty()){
                if(c == ')' || c == '}' || c == ']' ){
                    return false;
                }
            }
            if(c == ')')
            {
                 if(st.top() == '('){
                    st.pop();
                }
                else{
                    return false;
                }
            }  
            else if(c == '}')
            {
                 if(st.top() == '{'){
                    st.pop();
                }
                else{
                    return false;
                }
            } 
            else if(c == ']' )
            {
                if(st.top() == '['){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            

        }
        if(!st.empty()){
            return false;
        }
        return true;
        













































        // stack<char> st;
        // map<char, char> mp;
        // // Step 1: Store mappings
        // mp[')'] = '(';
        // mp['}'] = '{';
        // mp[']'] = '[';

        // // Step 2: Traverse string
        // for (char ch : s) 
        // {
        //     // If opening bracket → push
        //     if (ch == '(' || ch == '{' || ch == '[') 
        //     {
        //         st.push(ch);
        //     }
        //     else 
        //     {
        //         // If stack empty → invalid
        //         if (st.empty()) return false;

        //         // Check match using map
        //         if (st.top() == mp[ch]) 
        //         {
        //             st.pop();
        //         } 
        //         else 
        //         {
        //             return false;
        //         }
        //     }
        // }
        // return st.empty();
    }
};