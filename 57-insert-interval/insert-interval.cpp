
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        int n = intervals.size();

        if (n == 0) return {};

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;

        int start1 = intervals[0][0];
        int end1 = intervals[0][1];

        for (int i = 1; i < n; i++)
        {
            int start2 = intervals[i][0];
            int end2 = intervals[i][1];

            if (end1 >= start2)
            {
                end1 = max(end1, end2);
            }
            else
            {
                res.push_back({start1, end1});
                start1 = start2;
                end1 = end2;
            }
        }

        res.push_back({start1, end1});
        return res;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals,vector<int>& newInterval) 
    {
        int n = intervals.size();
        vector<vector<int>> res;
        bool inserted = false;

        for (int i = 0; i < n; i++)
        {
            if (intervals[i][0] < newInterval[0])
            {
                res.push_back(intervals[i]);
            }
            else
            {
                if (!inserted)
                {
                    res.push_back(newInterval);
                    inserted = true;
                }

                res.push_back(intervals[i]);
            }
        }

        if (!inserted)
        {
            res.push_back(newInterval);
        }

        return merge(res);
    }
};
