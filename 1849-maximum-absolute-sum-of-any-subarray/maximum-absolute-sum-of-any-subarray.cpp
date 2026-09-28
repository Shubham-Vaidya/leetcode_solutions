class Solution {
public:

     int maxsum(vector<int>& nums){
        int maxi = nums[0];
        // int sum = ;
        int best_ending = nums[0];
        
        for(int i = 1 ; i < nums.size(); i++)
        {
            best_ending += nums[i];
            int curr = nums[i];
            best_ending = max(best_ending,curr);              

            maxi = max(maxi,best_ending);     

            
        } 
        return maxi;
    }
    int minsum(vector<int>& nums){
        int mini = nums[0];
        // int sum = ;
        int best_ending = nums[0];
        
        for(int i = 1 ; i < nums.size(); i++)
        {
            best_ending += nums[i];
            int curr = nums[i];
            best_ending = min(best_ending,curr);              

            mini = min(mini,best_ending);     

            
        } 
        return mini;
    }

    int maxAbsoluteSum(vector<int>& nums) {
        int v1 = maxsum(nums);
        int v2 = abs(minsum(nums));
        return max(v1,v2);
    }

   
};