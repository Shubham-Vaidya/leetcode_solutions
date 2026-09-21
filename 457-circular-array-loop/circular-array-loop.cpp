class Solution {
public:

    int nextIndex(int i, vector<int>& nums) {
        int n = nums.size();

        return (i + nums[i] % n + n) % n;
    }

    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            bool forward = nums[i] > 0;

            int slow = i;
            int fast = i;

            while (true) {

                // Move slow one step
                int nextSlow = nextIndex(slow, nums);

                // Direction changed
                if ((nums[nextSlow] > 0) != forward)
                    break;

                // Move fast one step
                int nextFast = nextIndex(fast, nums);

                // Direction changed
                if ((nums[nextFast] > 0) != forward)
                    break;

                // Move fast second step
                nextFast = nextIndex(nextFast, nums);

                // Direction changed
                if ((nums[nextFast] > 0) != forward)
                    break;

                slow = nextSlow;
                fast = nextFast;

                // Cycle found
                if (slow == fast) {

                    // Reject single-element cycle
                    if (slow == nextIndex(slow, nums))
                        break;

                    return true;
                }
            }
        }

        return false;
    }
};