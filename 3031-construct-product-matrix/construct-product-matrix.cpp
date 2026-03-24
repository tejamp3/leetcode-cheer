class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
		const int n = grid.size(), m = grid.front().size();
		vector<vector<int>> gr(n, vector<int>(m));
		uint64_t pref = 1, suf = 1;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				gr[i][j] = pref;
				pref = pref * grid[i][j] % 12345;
			}
		}

		for (int i = n-1; i >= 0; --i) {
			for (int j = m-1; j >= 0; --j) {
				gr[i][j] = gr[i][j] * suf % 12345;
				suf = suf * grid[i][j] % 12345;
			}
		}


		return gr;
    }
};