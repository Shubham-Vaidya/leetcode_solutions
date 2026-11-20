class Solution {
public:

    struct cmp{
        bool operator()(const pair<int,int>&a , const pair<int,int>&b){
            if(a.first != b.first)
                return a.first < b.first;
            return a.second < b.second;
        }
    };

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        cmp
        >pq;
        vector<int> res;
        for(int i = 0 ; i < k ; i++){
            int diff = abs(arr[i] - x);
            pair<int,int> curr = {diff,arr[i]};
            pq.push(curr);
        }

        for(int i = k ; i < n ; i++){
            int diff = abs(arr[i] - x);
            pair<int,int> curr = {diff,arr[i]};
            pq.push(curr);
            pq.pop();
        }

        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        sort(res.begin(),res.end());

        return res;
    }
};