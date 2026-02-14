class Solution {

    
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
        queue<tuple<int , int ,  double>> q;

        vector<vector<double>> dp(101 , vector<double> ( 101 , 0.0));

        dp[0][0] = (1.0 * poured);
    
        int up = 1;
        for(int i = 0 ; i < 100 ; i++){
            bool found = false;
            for(int j = 0 ; j < min( 101 , up) ; j ++){
                if(dp[i][j] > 1.0){
                    found = true;
                    double x = (dp[i][j] - 1.0) / 2.0;
                    dp[i][j] = 1.0;
                    if(x > 0);
                    dp[i+1][j] += x;
                    dp[i+1][j+1] += x;
                }
            }

            if( up < 100 ){
                up *= 2;
            }

            if(!found){
                break;
            }
        }

        return dp[query_row][query_glass];

    }
};