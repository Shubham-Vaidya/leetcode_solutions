class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mpp;
        int n = s.size();
        int max_odd = 0;
        bool odds = false;
        for(int i = 0 ; i < n ; i++){
            char c = s[i];
            mpp[c]++;
        }
            int res = 0;
        for(auto it : mpp){
            if((it.second) % 2 == 0){
                res += it.second;
            }
            else{
                odds = true;
                int odd = it.second;
                max_odd = max(max_odd,odd);
                res += odd-1;
            }
                
        }
        // res = res+max_odd
        // res = res+1;
        // res = res-max_odd;
        if(odds)
        return res+1;
        else
        return res;
    }
};