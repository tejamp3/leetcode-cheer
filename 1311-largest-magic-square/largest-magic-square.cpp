class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& nums) {
        int n = nums.size() ;
        int m = nums[0].size() ;

        vector<vector<int>>rowsum(n,vector<int>(m,0)) ;
        vector<vector<int>>colsum(n,vector<int>(m,0)) ;

        for(int i=0 ; i<n ; i++ ) {
            rowsum[i][0] = nums[i][0] ;
            for(int j=1 ; j<m ; j++ ) {
                rowsum[i][j] = nums[i][j] + rowsum[i][j-1] ;
            }
        }

        for(int j=0 ; j<m ; j++ ) {
            colsum[0][j] = nums[0][j] ;
            for(int i=1 ; i<n ; i++ ) {
                colsum[i][j] = nums[i][j] + colsum[i-1][j] ;
            }
        }

        for(int side = min(n,m) ; side >= 2 ; side--) {
            for(int i=0 ;i<n-side+1 ; i++) {
                for(int j=0 ;j<m-side+1 ; j++ ) {
                    int target = rowsum[i][j+side-1] - (j>0 ? rowsum[i][j-1] : 0) ;
                    bool match = true ;
                    for(int r = i+1 ; (r < i+side)&&(match) ; r++) {
                        int curr = rowsum[r][j+side-1] - (j>0 ? rowsum[r][j-1] : 0) ;
                        if(curr != target ) match = false ;
                    }
                    for(int c=j ; (c<j+side) && match ; c++ ) {
                        int curr = colsum[i+side-1][c] - (i>0 ? colsum[i-1][c] : 0) ;
                        if(curr != target) match = false ;
                    }

                    int diagonal1 = 0,diagonal2 = 0 ;

                    for(int r=i,c=j,count = 0 ; count < side ; count++,r++,c++) {
                        diagonal1 += nums[r][c] ;
                    }
                    for(int r=i,c=j+side-1,count = 0 ; count < side ; count++,r++,c--) {
                        diagonal2 += nums[r][c] ;
                    }
                    if(diagonal1 != target ) match = false ;
                    if(diagonal2 != target ) match = false ;

                    if(match) return side ;
                }
            }
        }

        return 1 ;
    }
};