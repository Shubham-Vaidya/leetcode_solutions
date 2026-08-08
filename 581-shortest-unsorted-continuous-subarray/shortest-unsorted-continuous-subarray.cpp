class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int curr = 0;
        int back = n-1;
        int left = 0,right = 0;
        int max = nums[curr];
        int min = nums[n-1];
        while(curr < n-1){
            if(max <= nums[curr+1]){
                // if(max < nums[curr+1])
                max = nums[curr+1];
                curr++;
            }
            else {
                right = curr+1;
                curr++;
            }
        }
             while(back > 0)
             {
            if(nums[back-1] <= min)
            {
                min = nums[back-1];
                back--;
            }
            else 
            {
                left = back-1;
                back--;
            }

        }
        // sort(start,mid);
        if(left == right)return left;
        else
        return {right-left+1};
    }
};