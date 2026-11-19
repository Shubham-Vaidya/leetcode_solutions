class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        
        priority_queue<
        pair<int, int>,
        vector<pair<int, int>>
        > pq;

        for(int i = 0 ; i < k ; i++){
            int dist = pow(points[i][0], 2) + pow(points[i][1], 2);
            pair<int,int> curr = {dist,i};
            pq.push(curr);
        }

        for(int i = k ; i < n ; i++){
            int dist = pow(points[i][0], 2) + pow(points[i][1], 2);
            pair<int,int> curr = {dist,i};
            pq.push(curr);
            pq.pop();
        }

        vector<vector<int>> res;
        while (!pq.empty()) {
        res.push_back(points[pq.top().second]);
        pq.pop();
        }

        return res;
    }
};