class Solution {
public:

    int guess(vector<vector<int>>& matrix, int k, int mid) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = n-1;
        int col = 0;
        int result = 0;

        while((0 <= row && row <= n-1) && (0 <= col && col <= m-1)) {
            long num = matrix[row][col];

            if(num > mid) row--;
            else {
                result += row+1;
                col++;
            } 
        }
        return result;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();

        long long low = matrix[0][0];
        long long high = matrix[n-1][m-1];

        int res = 0;

        while(low <= high) {
            int mid = low + (high-low)/2;
            int ans = guess(matrix, k, mid);

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