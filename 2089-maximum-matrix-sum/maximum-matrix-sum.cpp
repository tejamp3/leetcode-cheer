class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long n = matrix.size(); 
        long long neg = 0 ; 
        long long least = INT_MAX ;
        long long  total = 0 ;
        for(int i = 0 ; i< n ; i++){
            for(int j =0 ; j < n ; j++){
                if(matrix[i][j]<0){
                    neg++ ; 
                }
                least = min((long long)least ,(long long) abs(matrix[i][j]));
                total += abs(matrix[i][j]);
            }
        }
        if(neg%2){
            return total- 2*least; 
        }
        else{
            return total ; 
        }
        return 0 ; 
        
        // Thought process:

        // If two negatives are adjacent, just convert them into positive and add to the total.
        // If one is negative, multiply if abs(negative) > positive above or positive below.
        // If none, don’t do anything.


        // Final intuition:
        // If the number of negatives is odd, add everything and subtract the smallest number.
        // If the number of positives is even, add everything.

        // Reason:
        // Think if there is one zero, but n operations, you can bring the negative sign to the smallest number.
        // Similarly, try with three negative numbers: you can convert two negatives to positive by bringing them near.
        // Likewise, for an even number of negatives, we can bring them near and convert them to positive.

    }
};