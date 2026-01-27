
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        int k = s.size();

        for (int i = 0; i < k; i++) {
            vector<int> hmap(256, 0);   // reset for each i

            for (int j = i; j < k; j++) {
                if (hmap[s[j]] == 1)
                    break;

                hmap[s[j]]++;           // mark character as seen
                int l = j - i + 1;
                max_len = max(max_len, l);
            }
        }
        return max_len;
    }
};
