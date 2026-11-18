class Solution {
public:

    struct cmp{
        bool operator()(const pair<int,string>&a , const pair<int,string>&b)
        const {
            if(a.first!= b.first)
                return a.first > b.first;
            return a.second < b.second;
        }

    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        // use a min heap 
        // use a hashmap to store all words and their frequency
        // push first k elements of the hashmap in the min heap
        // for all n-k elements n is the size of hashmap push the element in the min heap and sun=bsequently pop the top of min heap 
        // finally make a vector<char> res to store all the elements in the min heap in the lexicographical order

        unordered_map<string, int> mpp;

        for (auto word : words) {
            mpp[word]++;
        }

        priority_queue<
        pair<int, string>,
        vector<pair<int, string>>,
        cmp
        > pq;

        for (auto i : mpp) {
        int freq = i.second;
        string word = i.first;

        pair<int, string> curr = {freq, word};

        if (pq.size() < k) {
            pq.push(curr);
        }
        else {
            pq.push(curr);
            pq.pop();
        }
        }

        vector<string> res;

        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};