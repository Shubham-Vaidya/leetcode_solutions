class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
    int n = nums.size(); //size of array.

    int min_end = nums[0];
    int max_end = nums[0];
    int result = nums[0];
    for (int i = 1; i < n; i++) 
    {
        int curr = nums[i];
        int v2 = min_end*nums[i];
        int v3 = max_end*nums[i]; 

        max_end = max({v2,v3,curr});
        min_end = min({v3,v2,curr});
        result = max(result,max(min_end,max_end));
    }
    return result;  
    }  
};