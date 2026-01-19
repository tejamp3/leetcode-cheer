class Solution {
public:
    bool check(int len, vector<vector<long long>>& prefix,
               int m, int n, int threshold) {

        if (len == 0) return true;

        for (int i = len - 1; i < m; i++) {
            for (int j = len - 1; j < n; j++) {

                long long sum = prefix[i][j];

                if (i >= len) sum -= prefix[i - len][j];
                if (j >= len) sum -= prefix[i][j - len];
                if (i >= len && j >= len)
                    sum += prefix[i - len][j - len];

                if (sum <= threshold) return true;
            }
        }
        return false;
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();

        // 🔹 Correct initialization
        vector<vector<long long>> prefix(m, vector<long long>(n));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                prefix[i][j] = mat[i][j];

        // Row prefix
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                prefix[i][j] += prefix[i][j - 1];
            }
        }

        // Column prefix
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                prefix[i][j] += prefix[i - 1][j];
            }
        }

        int low = 0, high = min(m, n), ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid, prefix, m, n, threshold)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};