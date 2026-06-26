class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        int n=g.size();
        int k = s.size();
        int i =0;
        int j =0;
        while (i<n && j<k){
            if(s[j]>=g[i]){
                i++;
            }
            j++;
        }
        
    return i;
}
};