
        
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> res(n, -1);
        stack<int> st;  // Stores indices

        for (int i = 0; i < 2 * n; i++) {
            int idx = i % n;

            while (!st.empty() && nums[st.top()] < nums[idx]) {
                res[st.top()] = nums[idx];
                st.pop();
            }

            if (i < n) {
                st.push(i);
            }
        }

        return res;
    }
};

        // for(int i = 0 ; i < n ; i++){
        //     int curr = nums[i];
        //     int index = i;
        //     bool found = false;
        //     int next_index = (index + 1)%n;
        //     while(next_index != index){
        //         if(nums[next_index] > nums[index]){
        //             res.push_back(nums[next_index]);
        //             found = true;
        //             break;
        //         }
        //         else{
        //             next_index = (next_index + 1)%n;
        //         }
        //     }
        //     if(!found) res.push_back(-1);
        // }
        // return res;
//     }
// };