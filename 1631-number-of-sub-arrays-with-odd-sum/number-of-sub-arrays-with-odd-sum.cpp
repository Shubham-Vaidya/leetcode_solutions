class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int MOD = 1e9 + 7;

        long long evenCount = 1;
        long long oddCount = 0;

        long long ans = 0;
        int prefixSum = 0;

        for(int i = 0; i < arr.size(); i++) {

            prefixSum += arr[i];

            if(prefixSum % 2 == 0) {

                // Current prefix is even.
                // Pair it with all previous odd prefixes.
                ans = (ans + oddCount) % MOD;

                evenCount++;
            }
            else {

                // Current prefix is odd.
                // Pair it with all previous even prefixes.
                ans = (ans + evenCount) % MOD;

                oddCount++;
            }
        }

        return ans;
    }
};