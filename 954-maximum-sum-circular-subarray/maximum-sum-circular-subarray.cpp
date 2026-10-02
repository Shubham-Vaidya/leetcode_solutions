class Solution {
public:
    int minsum(vector<int>& nums) {
        int mini = nums[0];
        int best_ending = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            best_ending = min(nums[i], best_ending + nums[i]);
            mini = min(mini, best_ending);
        }

        return mini;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int v1 = minsum(nums);

        int sum = 0;
        int maxSum = nums[0];
        int curr = nums[0];

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        for(int i = 1; i < nums.size(); i++) {
            curr = max(nums[i], curr + nums[i]);
            maxSum = max(maxSum, curr);
        }

        int v2 = sum - v1;

        if(maxSum < 0)
            return maxSum;

        return max(maxSum, v2);
    }
};