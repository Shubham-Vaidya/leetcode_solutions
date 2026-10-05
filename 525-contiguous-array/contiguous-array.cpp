class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int zero = 0;
        int one = 0;
        int res = 0;
        unordered_map <int,int> mpp;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 0)
                zero++;
            else
                one++;
        int diff = zero - one;
        if(diff == 0){
            res = max(res,i+1);
             continue;       
        }
        if(mpp.find(diff) == mpp.end()){
            mpp[diff] = i;
        }
        else{
            int index = mpp[diff];
            int len = i - index;
            res = max(res,len); 
        }
    }
    return res;
    }
    
};