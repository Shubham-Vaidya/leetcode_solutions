class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0;
        int high = n*m-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            int row = mid/m;
            int col = mid%m;
            if(matrix[row][col] == target)
                return true;
            else if(matrix[row][col] < target)
                low = mid+1;
            else
                high = mid-1;
        }
       
        return false;






































        // int m = matrix.size();
        // int n = matrix[0].size();

        // int left = 0;
        // int right = m * n - 1;

        // while (left <= right) {
        //     int mid = left + (right - left) / 2;

        //     int row = mid / n;
        //     int col = mid % n;

        //     if (matrix[row][col] == target)
        //         return true;
        //     else if (matrix[row][col] < target)
        //         left = mid + 1;
        //     else
        //         right = mid - 1;
        // }

        // return false;
    }
};