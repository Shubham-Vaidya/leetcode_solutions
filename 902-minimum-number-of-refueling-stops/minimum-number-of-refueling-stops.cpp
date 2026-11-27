class Solution {
public:

    struct cmp{
        bool operator()(const pair<int,int> &a , const pair<int,int> &b){
            if(a.first != b.first)
                return a.first < b.first;
            return a.second < b.second;
        }
    };

    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int count = 0;
        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        cmp
        >pq;
        vector<pair<int,int>> stops;
        for(int i = 0 ; i < stations.size() ; i++){
            stops.push_back({stations[i][0],stations[i][1]});
        }
        sort(stops.begin(),stops.end());
        int index = 0;
        while(target > startFuel){
            while(index < stops.size()){
            if(startFuel < stops[index].first)
                break;
            pq.push({stops[index].second,stops[index].first});
                index++; 
        }

        if(pq.empty())
            return -1;

             
            startFuel = startFuel  + pq.top().first;
            pq.pop();
             count++;
            if(target <= startFuel) return count;
           
        }
        return count;
    }
};