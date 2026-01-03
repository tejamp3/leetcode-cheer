class Solution {
public:
    int numOfWays(int n) {
        const long MOD = 1e9 + 7;

        // Base case for n = 1
        // typeA represents patterns like 121 (first and last color same)
        // typeB represents patterns like 123 (all three colors different)
        long typeA = 6; 
        long typeB = 6; 

        for (int i = 1; i < n; ++i) {
            // Calculate next state based on transitions
            // If prev is ABA: 3 ways to be ABA, 2 ways to be ABC
            // If prev is ABC: 2 ways to be ABA, 2 ways to be ABC
            long newA = (typeA * 3 + typeB * 2) % MOD;
            long newB = (typeA * 2 + typeB * 2) % MOD;
            
            // Update states for the next iteration
            typeA = newA;
            typeB = newB;
        }

        return (typeA + typeB) % MOD;
    }
};