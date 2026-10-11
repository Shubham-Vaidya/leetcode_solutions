#include <vector>
#include <unordered_map>

class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        // Hash map to store the number and its most recent index
        std::unordered_map<int, int> numIndices;

        for (int i = 0; i < nums.size(); ++i) {
            // Check if the number has been seen before
            if (numIndices.find(nums[i]) != numIndices.end()) {
                // Check if the absolute difference in indices is <= k
                if (i - numIndices[nums[i]] <= k) {
                    return true;
                }
            }
            // Update the map with the latest index of the current number
            numIndices[nums[i]] = i;
        }

        // No such duplicate pair found within distance k
        return false;
    }
};