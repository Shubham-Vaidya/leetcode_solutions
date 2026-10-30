class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());

        int n = piles.size();
        int low = 1;
        int high = piles[n-1];
        int ans = high;

        while(low <= high) {
            int mid = low + (high-low)/2;
            int sum = 0;

            for(int i = 0; i < n; i++) {
                sum += (piles[i] + mid - 1) / mid;
                // sum += piles[i]/mid + piles[i]%mid;

                if(sum > h) break;
            }

            if(sum <= h) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};