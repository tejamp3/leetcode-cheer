class Solution {
public:
    int longestBalanced(string s) {
        map<array<int, 3>, int> mp;
        mp[{0, 0, 0}] = -1;
        vector<int> cur(3, 0);
        int ans = 0, n = s.size();
        for(int i = 0; i < n; i++) {
            cur[s[i] - 'a']++;
            int mn = *min_element(cur.begin(), cur.end());
            for(int i = 0; i < 3; i++) cur[i] -= mn;
            array<int, 3> t = {cur[0], cur[1], cur[2]};
            if(mp.contains(t)) ans = max(ans, i - mp[t]);
            else mp[t] = i;
        }
        int *t = &ans;
        auto for2 = [&](char a, char b) {
            vector<vector<int>> pos(2 * n + 1);
            pos[n].push_back(-1);
            int cnt = n, last = -1, ans = 0;
            for(int i = 0; i < n; i++) {
                if(s[i] == a) cnt--;
                else if(s[i] == b) cnt++;
                else last = i;
                if(!pos[cnt].empty()) {
                    int l = 0, r = pos[cnt].size() - 1;
                    while(l < r) {
                        int m = (l + r) / 2;
                        if(pos[cnt][m] >= last) r = m;
                        else l = m + 1;
                    }
                    if(pos[cnt][l] >= last) ans = max(ans, i - pos[cnt][l]);
                }
                pos[cnt].push_back(i);
            }
            if(*t < ans) *t = ans;
        };
        auto for1 = [&](char a) {
            int last = -1, ans = 0;
            for(int i = 0; i < n; i++) {
                if(s[i] == a) ans = max(ans, i - last);
                else last = i;
            }
            if(*t < ans) *t = ans;
        };
        for2('a', 'b');
        for2('a', 'c');
        for2('b', 'c');
        for(int i = 0; i < 3; i++) for1('a' + i);
        return ans;
    }
};
