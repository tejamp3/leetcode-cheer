class Solution {
public:
    int countBinarySubstrings(string s) {
        
        int n = s.size();

        vector<int> zeroLeft(n), zeroRight(n), oneLeft(n), oneRight(n);

        int cnt1 = 0, cnt2 = 0;

        for(int i = 0; i < n; ++i) {

            if(s[i] == '0') {

                cnt1++;
                cnt2 = 0;
            }
            else {

                cnt2++;
                cnt1 = 0;
            }

            zeroLeft[i] = cnt1;
            oneLeft[i] = cnt2;
        }

        cnt1 = 0, cnt2 = 0;

        for(int i = n - 1; i >= 0; --i) {

            if(s[i] == '0') {

                cnt1++;
                cnt2 = 0;
            }
            else {

                cnt2++;
                cnt1 = 0;
            }

            zeroRight[i] = cnt1;
            oneRight[i] = cnt2;
        }

        int ans = 0;

        for(int i = 1; i < n; ++i) {

            if(s[i - 1] == '0' && s[i] == '1') {

                ans += min(zeroLeft[i - 1], oneRight[i]);
            }
            else if(s[i - 1] == '1' && s[i] == '0') {

                ans += min(oneLeft[i - 1], zeroRight[i]);
            }
        }

        return ans;
    }
};