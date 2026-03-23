class Solution {
public:
    bool hasZero = false;
    // Return <Min Neg, Max Pos>
    pair<long long,long long> getProduct(vector<vector<int>> &grid, int x, int y, int m, int n,vector<vector<pair<long long,long long>>> &dp){
        pair<long long,long long> right, bottom, curRes;
        long long cur = grid[x][y];
        if(cur == 0) hasZero = true;
        if(x == m-1 && y == n-1){
            if(cur < 0) return {cur,0};
            return {0,cur};
        }
        if(dp[x][y].first != LLONG_MIN) return dp[x][y];
        // Move to right
        if(y+1 < n) right = getProduct(grid,x,y+1,m,n,dp);
        // Move to bottom
        if(x+1 < m) bottom = getProduct(grid,x+1,y,m,n,dp);
        // Now we have 4 values
        if(cur < 0){ // Then neg max gives positive  
            curRes = {min(right.second*cur, bottom.second*cur), 
                max(right.first*cur, bottom.first*cur)};
        }else{
            curRes = {min(right.first*cur, bottom.first*cur), 
                max(right.second*cur, bottom.second*cur)};
        }
        // cout<<x<<", "<<y<<" : "<<curRes.first<<", "<<curRes.second<<endl;
        return dp[x][y] = curRes;
    }
    int maxProductPath(vector<vector<int>>& grid) {
        int mod = 1e9+7;
        int m = grid.size(), n = grid[0].size();
        vector<vector<pair<long long,long long>>> dp(m,vector<pair<long long,long long>>(n,{LLONG_MIN,LLONG_MIN}));
        pair<long long,long long> res = getProduct(grid,0,0,m,n,dp);
        // cout<<res.first<<", "<<res.second<<endl;
        if(res.second <= 0) return hasZero?0:-1;
        return res.second%mod;
    }
};