
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low <= high) {
            int mid = low + (high - low) / 2;

            int curr = 0;
            int count = 1;

            for(int num : nums) {
                if(curr + num <= mid) {
                    curr += num;
                }
                else {
                    count++;
                    curr = num;
                }
            }

            if(count <= k) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};
