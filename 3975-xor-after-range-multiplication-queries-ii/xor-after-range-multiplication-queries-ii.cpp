class Solution {
    long long power(long long base, long long exp) {
        long long res = 1;
        long long mod = 1e9 + 7;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) 
                res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n) {
        return power(n, 1e9 + 5);
    }

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        long long MOD = 1e9 + 7;
        int n = nums.size();
        if (n == 0) 
            return 0;

        int square = sqrt(n) + 1;
        unordered_map<int, vector<vector<int>>> small;
        vector<long long> numL(nums.begin(), nums.end());

        for (auto& q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (k >= square) {
                for (int idx = l; idx <= r; idx += k) {
                    numL[idx] = (numL[idx] * v) % MOD;
                }
            } else {
                small[k].push_back({l, r, v});
            }
        }

        vector<long long> factors(n, 1);
        for (auto const& [k, qlist] : small) {
            vector<vector<pair<int, int>>> events(k);
            for (auto& q : qlist) {
                int l = q[0], r = q[1], v = q[2];
                int res = l % k;
                int last = l + ((r - l) / k) * k;
                events[res].push_back({l, v});
                int end_idx = last + k;
                if (end_idx < n) {
                    events[res].push_back({end_idx, (int)modInverse(v)});
                }
            }

            for (int res = 0; res < k; ++res) {
                if (events[res].empty()) 
                    continue;
                sort(events[res].begin(), events[res].end());
                long long cur = 1;
                int ptr = 0;
                for (int i = res; i < n; i += k) {
                    while (ptr < events[res].size() && events[res][ptr].first == i) {
                        cur = (cur * events[res][ptr].second) % MOD;
                        ptr++;
                    }
                    factors[i] = (factors[i] * cur) % MOD;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans ^= (int)((numL[i] * factors[i]) % MOD);
        }
        return ans;
    }
};