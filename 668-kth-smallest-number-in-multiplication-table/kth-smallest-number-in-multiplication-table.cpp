class Solution {
public:

    int guess(int m, int n, int k, int mid) {
        int row = m-1;
        int col = 0;
        int result = 0;

        while((0 <= row && row <= m-1) && (0 <= col && col <= n-1)) {
            int num = (row+1)*(col+1);

            if(num > mid) row--;
            else {
                result += row+1;
                col++;
            }
        }
        return result;
    }

    int findKthNumber(int m, int n, int k) {
        int low = 1;
        int high = m*n;
        int res = 0;

        while(low <= high) {
            int mid = low + (high-low)/2;
            int ans = guess(m,n,k,mid);

            if(ans >= k) {
                high = mid-1;
                res = mid;
            }
            else {
                low = mid+1;
            }
        }
        return res;
    }
};