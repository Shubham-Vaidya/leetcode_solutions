class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mpp1;
        unordered_map<char,int> mpp2;

        int n = ransomNote.size();
        int m = magazine.size();
        for(int i = 0 ; i < n ; i++){
            char c = ransomNote[i];
            mpp1[c]++;
        }
        for(int i = 0 ; i < m ; i++){
            char c = magazine[i];
            mpp2[c]++;
        }
        for (auto it : mpp1) 
        {
            char key = it.first;

            if (mpp2.find(key) != mpp2.end()) 
            {
                if (it.second <= mpp2[key]) {
                    continue;
                } 
                else{
                return false;
                }
            }
            else
            return false;

        }
        return true;
    }
};