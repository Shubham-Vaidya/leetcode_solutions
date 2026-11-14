class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) 
    {
        // sort(nums.begin(),nums.end());
        int length = l;
        int n = nums.size();
        long long res = LLONG_MAX;

        while(length <= r)
        {
            int low = 0;
            int high = low + length-1;
            long long sum = 0;

            while(low <= high){
                sum += nums[low];
                low++;
            }

            low = 0;
            while(high < n)
            {
                long long prev_sum = sum;
                if(prev_sum > 0){
                    res = min(res,prev_sum);
                    // break;
                } 
                sum -= nums[low];
                low++;
                high++;
                if(high < n)
                    sum += nums[high];
            }
            length++;
        }
        if(res == LLONG_MAX)
            return -1;
        else return (int)res;
    }
};