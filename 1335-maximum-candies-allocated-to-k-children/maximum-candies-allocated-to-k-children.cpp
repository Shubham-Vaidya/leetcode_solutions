class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        sort(candies.begin(), candies.end());

        long long n = candies.size();
        long long low = 1;
        long long high = candies[n-1];

        if(k > n){
            long long sum = 0;
            for(auto it : candies){
                sum += it;
            }
            if(sum < k) return 0;
        }

        long long final = 0;

        while(low <= high){
            long long mid = low + (high-low)/2;
            long long res = 0;

            for(long long i = 0; i < n; i++){
                res += candies[i]/mid;
            }

            if(res >= k){
                final = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        return (int)final;
    }
};