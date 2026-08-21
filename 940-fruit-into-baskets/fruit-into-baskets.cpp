// class Solution {
// public:
//     int totalFruit(vector<int>& fruits) {
       
//        int length = 0;
//        int n = fruits.size();
//        int low = 0;
//        int high = 0;
//        int result = INT_MIN;
//        map<int,int> mpp;

//        while(high < n){
        
//        if(mpp.find(fruits[high]) == mpp.end() && mpp.size() < 2){
//             mpp[fruits[high]] = 1;
//             high++;
//        }
//        else if(mpp.find(fruits[high]) != mpp.end()){
//             mpp[fruits[high]]++;
//             high++;
//        }
//        else{
//             mpp[fruits[high]] = 1;
//             high++;
            
//             while(mpp.size() > 2){
//                 mpp[fruits[low]]--;

//                 if(mpp[fruits[low]] == 0){
//                     mpp.erase(fruits[low]);
//                 }

//                 low++;
//             }

//             length = high - low;
//             result = max(result, length);
//        }
//     }
    
//     // Important: handle the final valid window
//     length = high - low;
//     result = max(result, length);
    
//     return result;
//     }
// };

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int low = 0;
        int high = 0;
        int result = 0;
        map<int, int> mpp;

        while (high < n) {
            mpp[fruits[high]]++;
            high++;

            while (mpp.size() > 2) {
                mpp[fruits[low]]--;

                if (mpp[fruits[low]] == 0) {
                    mpp.erase(fruits[low]);
                }

                low++;
            }

            int length = high - low;
            result = max(result, length);
        }

        return result;
    }
};