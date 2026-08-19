class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> nums;
        int i = 0;
        int j = 0;
        int k = -1;

        while (i < operations.size()) {

            if (isdigit(operations[i][0]) || operations[i][0] == '-') {
                nums.push_back(stoi(operations[i]));
                j++;
                k++;
            }

            else if (operations[i] == "C") {
                if (nums.size() != 0) {
                    nums.erase(nums.begin() + j - 1);
                    j--;
                    k--;
                }
            }

            else if (operations[i] == "D") {
                nums.push_back(nums[j - 1] * 2);
                j++;
                k++;
            }

            else if (operations[i] == "+") {
                nums.push_back(nums[j - 1] + nums[k - 1]);
                j++;
                k++;
            }

            i++;
        }

        int sum = 0;

        for (int x : nums) {
            sum += x;
        }

        return sum;
    }
};