class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = n-1;
        int col = 0;
        while((0 <= row && row <= n-1) &&(0 <= col && col <= m-1)){
            long num = matrix[row][col];
            if(num == target) return true;
            else if(num > target) row--;
            else col++; 
        }
        return false;
    }
};