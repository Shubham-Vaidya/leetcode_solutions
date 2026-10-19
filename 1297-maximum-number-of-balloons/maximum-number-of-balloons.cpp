class Solution {
public:
    int maxNumberOfBalloons(string text) {
         unordered_map<char, int> mpp;

        // First pass: Count the frequency of every character
        for (int i = 0; i < text.size(); i++) {
            mpp[text[i]]++;
        }

        int b = mpp['b'];
        int a = mpp['a'];
        int l = mpp['l']/2;
        int o = mpp['o']/2;
        int n = mpp['n'];

        return min({b,a,l,o,n});

    }
};