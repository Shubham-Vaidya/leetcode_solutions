class Solution {
public:

    bool possible(vector<int>& citations , int mid){
        int temp = 0;
        for(int i = 0 ; i < citations.size(); i++){
            if(citations[i] >= mid) temp++;
            if(temp >= mid) return true;
        }
        return false;
    }

    int hIndex(vector<int>& citations) {
       int n = citations.size();
       int low = 0;
       int high = n;
       int res = 0;
       if(n == 1){
            if(citations[0] == 0)
                return 0;
       else
        return 1;
       }
       while(low <= high){
            int mid = low + (high-low)/2;
            if(possible(citations,mid)){
                res = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
       } 
            return res;
    }
};