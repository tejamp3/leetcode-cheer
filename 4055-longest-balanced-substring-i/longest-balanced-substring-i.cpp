class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int len = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mp;
            for (int j = i; j < n; j++) {
                mp[s[j]]++;

                bool check = true;
                int freq = -1;
                for (auto &it : mp) {
                    if (freq == -1) freq = it.second;
                    else if (it.second != freq) {
                        check = false;
                        break;
                    }
                }

                if (check) {
                    len = max(len, j - i + 1);
                }
            }
        }
        return len;
    }
};