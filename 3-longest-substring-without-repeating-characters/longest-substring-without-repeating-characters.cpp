class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int low = 0;
        int result = 0;
        int high = 0;
        map <char,int> mpp;
        if(n == 0)return 0;
        else if(n == 1) return 1;
        // else if(n == 2) return 2;
        while(high < n){
            if (mpp.find(s[high]) == mpp.end()){
                mpp[s[high]] = 1;
                high++;
                int length = high - low;
                result = max(result,length);
            }
            else if(mpp.find(s[high]) != mpp.end()){
                int length = high - low;
                result = max(result,length);
                while(mpp.find(s[high]) != mpp.end()){
                    mpp[s[low]]--;
                    mpp.erase(s[low]);
                    low++;  
                }
                 mpp[s[high]] = 1;
                 length = high - low;
                result = max(result,length);
                high++;
                 
                // if(high == low )return 1;
            }
           
        }
        return result;
    }
};