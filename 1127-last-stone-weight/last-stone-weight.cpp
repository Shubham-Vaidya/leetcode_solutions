class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int>pq;
        for(int i = 0 ; i < n ; i++){
            pq.push(stones[i]);
        }
        while(!pq.empty()){
            if(pq.size() == 1) return pq.top();
            else{
                int high = pq.top();
                pq.pop();
                int low = pq.top();
                pq.pop();
                int res = high - low;
                if(res > 0) pq.push(res);
                // if(pq.size() == 1) return pq.top();
            }
        }
        return 0;
    }
};