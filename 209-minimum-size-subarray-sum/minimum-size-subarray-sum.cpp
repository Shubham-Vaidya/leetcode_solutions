class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT_MAX;
        int n = nums.size();
        int low = 0;
        int high = 0;
        int sum = 0;
        int len = 0;
        while(high < n){
            sum = sum + nums[high];
            while(sum >= target){
                len = high - low + 1;
                result = min(result,len);
                sum = sum - nums[low];
                low++;
            }
            high++;
            
        }
        if(result == INT_MAX) return 0;
        return result;
    }
};