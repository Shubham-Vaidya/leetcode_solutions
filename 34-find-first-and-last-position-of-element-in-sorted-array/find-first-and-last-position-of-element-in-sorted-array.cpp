#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int res1 = -1;
        int res2 = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target ){
                res1 = mid;
                high = mid-1;
            }
            else if(nums[mid] < target) {
                low  = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        low = 0;
        high = n-1;
         while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target ){
                res2 = mid;
                low  = mid+1;
            }
            else if(nums[mid] < target) {
                low  = mid+1;
            }
            else{
                high = mid-1;
            }
        }
            return{res1,res2};
         

































        // int n = nums.size();
        
        // int low = 0;
        // int high = n-1;
        // // int mid = high/2;
        // while(low <= high){
        //     int mid = (low + (low - high)/2);
        //     if(nums[mid] == target){
        //         return [mid,mid+1];
        //     }
        //     else if(mid < target){
        //         low = mid+1;
        //     }
        //     else{
        //         high = high - 1;
        //     }
        //     return [-1,-1];
        // }
    }
};
