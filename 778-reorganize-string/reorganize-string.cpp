class Solution {
public:

    struct cmp {
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) {
            if (a.first != b.first)
                return a.first < b.first;
            return a.second < b.second;
        }
    };

    string reorganizeString(string s) {
        int n = s.size();

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            cmp
        > pq;

        unordered_map<char,int> mpp;

        for (int i = 0; i < n; i++) {
            mpp[s[i]]++;
        }

        for (auto i : mpp) {
            int freq = i.second;
            pair<int,int> curr = {freq, i.first};
            pq.push(curr);
        }

        vector<char> res;
        int seat = 0;

        while (!pq.empty()) {
            pair<int,int> p = pq.top();
            pq.pop();

            if (seat == 0 || res[seat - 1] != p.second) {
                res.push_back(p.second);
                seat++;

                p.first--;

                if (p.first > 0)
                    pq.push(p);
            }
            else {
                if (pq.empty())
                    return "";

                pair<int,int> p2 = pq.top();
                pq.pop();

                res.push_back(p2.second);
                seat++;

                p2.first--;

                if (p2.first > 0)
                    pq.push(p2);

                pq.push(p);
            }
        }

        return string(res.begin(), res.end());
    }
};