class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            int curr = nums[i];
            int index = i;
            bool found = false;
            int next_index = (index + 1)%n;
            while(next_index != index){
                if(nums[next_index] > nums[index]){
                    res.push_back(nums[next_index]);
                    found = true;
                    break;
                }
                else{
                    next_index = (next_index + 1)%n;
                }
            }
            if(!found) res.push_back(-1);
        }
        return res;
    }
};