class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int ans=0;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+grid[i-1][j-1];
                if(dp[i][j]<=k)ans++;
                else break;
            }
        }
        return ans;
    }
};
