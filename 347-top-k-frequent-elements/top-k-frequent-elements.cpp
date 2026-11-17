
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;
        unordered_map<int, int> mpp;

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }

        for (auto i : mpp) {
            int element = i.first;
            int freq = i.second;

            pair<int, int> curr = {freq, element};

            if (pq.size() < k) {
                pq.push(curr);
                continue;
            }

            if (curr.first < pq.top().first) continue;

            pq.pop();
            pq.push(curr);
        }

        vector<int> res;

        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
