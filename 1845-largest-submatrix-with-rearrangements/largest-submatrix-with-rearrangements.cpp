class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), count = 0, ans = 0, len;
        vector<multiset<int>> consOnes(n);
        for (int i = 0; i < m; i++) {
            count = 0;
            for (int j = 0; j < n; j++) {
                if (matrix[j][i] == 1)
                    count++;
                else
                    count = 0;
                if (count != 0)
                    consOnes[j].insert(-count);
            }
        }

        for (int i = 0; i < n; i++) {
            len = 1;
            for (auto& x : consOnes[i]) {
                ans = max(ans, (-x) * len);
                len++;
            }
        }
        return ans;
    }
};