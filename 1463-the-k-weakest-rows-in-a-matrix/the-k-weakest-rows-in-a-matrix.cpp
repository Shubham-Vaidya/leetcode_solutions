class Solution {
public:

    struct cmp{
        bool operator()(const pair<int,int>&a , const pair<int,int>&b){
            if(a.first != b.first)
                return a.first < b.first;
            return a.second < b.second;
        }
    };

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        cmp
        >pq;
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0 ; i < k ; i++)
        {

            int count = 0;
            for(int j = 0 ; j < m ; j++)
            {
                int value = mat[i][j];
                if(value == 1) count++;            
            }
            pair<int,int> curr = {count,i};
            pq.push(curr);
        }

        for(int i = k ; i < n ; i++)
        {
            int count = 0;
            for(int j = 0 ; j < m ; j++)
            {
                int value = mat[i][j];
                if(value == 1) count++;            
            }
            pair<int,int> curr = {count,i};
            pq.push(curr);
            pq.pop();
        }

        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
            reverse(res.begin(),res.end());
            return res;
    }
};