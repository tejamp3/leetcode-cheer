class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int result = 0, sum;
        vector<pair<int,bool>> col(cols);
        unordered_map<char, int> mp = {{'X', 1}, {'Y', -1}, {'.', 0}};
        for(int i = 0; i < rows; i++) {
            sum = 0;
            for(int j = 0; j < cols; j++) {
                if(mp[grid[i][j]] == 1 || (j >= 1 && col[j-1].second)){
                    col[j].second = true;
                }
                col[j].first += mp[grid[i][j]];
                sum += col[j].first;
                if(sum == 0  && col[j].second) {
                    result++;
                } 
            }
        }
        return result;
    }
};