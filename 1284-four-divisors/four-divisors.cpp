class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {

        int result = 0;

        for (int i = 0; i < nums.size(); i++) {

            vector<int> k;
            int n = nums[i];

            for (int j = 1; j * j <= n; j++) {

                if (n % j == 0) {
                    k.push_back(j);

                    if (j != n / j)
                        k.push_back(n / j);

                    if (k.size() > 4)
                        break;   // early exit
                }
            }

            if (k.size() == 4)
                result += accumulate(k.begin(), k.end(), 0);
        }

        return result;
    }
};
