class Solution {
public:
    int numOfWays(int n) {
        const int mod = 1e9 + 7;

        long long abc = 6;
        long long aba = 6;

        for (int i = 2; i <= n; i++) {
            long long newabc = (2 * abc + 2 * aba) % mod;
            long long newaba = (2 * abc + 3 * aba) % mod;

            abc = newabc;
            aba = newaba;
        }

        return (abc + aba) % mod;
    }
};