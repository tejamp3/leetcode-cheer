class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int c = 0;

        for (int j = 0; j < n; j++) {
            if (digits[j] == 9)
                c++;
        }

        if (c == n) {
            digits.resize(n + 1);
            digits[0] = 1;
            for (int j = 1; j <= n; j++) {
                digits[j] = 0;
            }
            return digits;
        }

        // 🔥 ALWAYS add 1 first
        digits[n-1]++;

        // 🔥 Fix carry propagation
        for (int i = n - 1; i > 0; i--) {
            if (digits[i] == 10) {
                digits[i] = 0;
                digits[i - 1]++;
            }
        }

        return digits;
    }
};
