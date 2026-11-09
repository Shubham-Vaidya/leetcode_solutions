class Solution {
public:
    int splitArray(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        
        int res = 0;
        
        while(low <= high){
            bool possible = true;
            int mid = low + (high-low)/2;
            int curr = 0;
            int count = 1;
            for(int i = 0 ; i < n ; i++){
                
                if(nums[i] > mid){
                    possible = false;
                    break;
                }
                if(curr + nums[i] <= mid){
                    curr += nums[i];
                }
                else{
                    count++;
                    curr = nums[i];
                }
            }
            if(possible && count <= k){
                res = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
            
        }
        return res;























    //     int sum = 1 , sumi = 0;
    //     for(int i = 0 ; i<nums.size() ; i++)
    //     {
    //         if(sumi + nums[i] <= mid)
    //             sumi += nums[i];
    //         else
    //         {
    //             sum++;
    //             sumi = nums[i];
    //         }
    //     }
    //     return sum;
    // }

    // int splitArray(vector<int>& nums, int k) 
    // {
    //     int low = *max_element(nums.begin(),nums.end());
    //     int high = accumulate(nums.begin(),nums.end(),0);
    //     int sum = 0;
    //     while(low <= high)
    //     {
    //         int mid = (low+high)/2;
    //          sum = Check(nums,mid);
    //         if(sum > k ) low = mid+1;
    //         else
    //             high = mid-1;
    //     }
    //     return low;
    }
};