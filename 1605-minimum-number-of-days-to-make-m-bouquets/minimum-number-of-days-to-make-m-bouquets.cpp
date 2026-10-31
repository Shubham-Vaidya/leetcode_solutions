#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    bool possible(vector<int>& arr, int mid, int k, int m) {
        int count = 0;
        int bouq = 0;

        for (int i = 0; i < arr.size(); i++) {

            if (bouq >= m) return true;

            if (arr[i] <= mid) {
                count++;
            }
            else {
                count = 0;
            }

            if (count == k) {
                count = 0;
                bouq++;
            }
        }

        return bouq >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        int n = bloomDay.size();

        if (1LL * m * k > n) return -1;

        int low = 1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        int res = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (possible(bloomDay, mid, k, m)) {
                high = mid - 1;
                res = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return res;
    }
};