class Solution {
public:
    int maximumSum(vector<int>& arr) {

        long long noDelete = arr[0];
        long long oneDelete = -1e18;
        long long answer = arr[0];

        for (int i = 1; i < arr.size(); i++) {

            long long newNoDelete = max(
                (long long)arr[i],
                noDelete + arr[i]
            );

            long long newOneDelete = max(
                oneDelete + arr[i],
                noDelete
            );

            noDelete = newNoDelete;
            oneDelete = newOneDelete;

            answer = max(answer, max(noDelete, oneDelete));
        }

        return (int)answer;
    }
};