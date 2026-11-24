class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        priority_queue<int>pq;
        vector<pair<int,int>> proj;
        for(int i = 0 ; i < n ; i++){
            proj.push_back({capital[i],profits[i]});
        }
        sort(proj.begin(),proj.end());
        int index = 0;
        while(k--){
            while(index < n){
                if(proj[index].first > w)
                    break;
                pq.push(proj[index].second);
                index++;
            }
            if(pq.empty())
                break;
            
            w = w + pq.top();
            pq.pop();
        }
        return w;
    }
};