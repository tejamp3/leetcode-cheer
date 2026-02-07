class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        int mini=n;

        unordered_map<char, int> pre, post;

        for(int i=0; i<n; i++){
            post[s[i]]++;
        }

        mini=post['a'];

        for(int i=0; i<n; i++){
            pre[s[i]]++;
            post[s[i]]--;
            int rem=pre['b']+post['a'];
            mini=min(rem, mini);
        }

        return mini;
    }
};