class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map <int,int> mpp;
        int n = nums.size();
        mpp[0] = 1;
        int sum = 0;
        int rem = 0;
        int res = 0;
        for(int i = 0; i < n ; i++){
            sum += nums[i];
            rem = sum % k;
            if(rem < 0)
                rem += k;
            res += mpp[rem];
            mpp[rem]++;
        }
        return res;
    }
};