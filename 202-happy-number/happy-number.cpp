class Solution {
public:

    int squared(int n) {
        int sum = 0;

        while (n > 0) {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        while (fast != 1) {
            slow = squared(slow);

            fast = squared(fast);
            fast = squared(fast);

            if (slow == fast && slow != 1)
                return false;
        }

        return true;
    }
};