// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) 
//     {
//         int maxi = INT_MIN;
//         int sum = 0;
//        // int start = 0 , ans_start = -1 ; ans_end = -1;
//         for(int i = 0 ; i < nums.size(); i++)
//         {
//             //if(sum == 0)
//             //start = i;

//             if(sum > maxi)
//             {
//                 maxi = sum;
//                 //ans_start = start; 
//                 //ans_end = i;
//             }

//             if(sum < 0)
//             {
//             sum = 0;
//             }
//         } 
//           return maxi;
//     }
// };

class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
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
};
