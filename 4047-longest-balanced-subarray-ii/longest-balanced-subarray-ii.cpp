class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        int sq=sqrt(n);
        int b=(n/sq)+1;
        vector<int>diff(n,0);
        vector<int>temp(b,0),mini(b,0),maxi(b,0);
        vector<int>end(100001,-1);
        int ans = 0;
        for(int i=0;i<n;i++) {
            int x;
            if(nums[i]%2 == 0) x = 1;
            else x = -1;
            int l = end[nums[i]] + 1;
            int r = i;
            end[nums[i]]=i;
            if(l<=r){
                int bs=l/sq;
                int be=r/sq;
                if(bs==be) {
                    int h=min(n,(bs+1)*sq); 
                    int ind=bs*sq; 
                    mini[bs]=INT_MAX;  
                    maxi[bs]=INT_MIN;
                    for(int j=ind;j<h;j++) {
                        if(j>=l&&j<=r) diff[j] = diff[j] + x;
                        mini[bs]=min(mini[bs], diff[j]);
                        maxi[bs]=max(maxi[bs], diff[j]);
                    }
                } 
                else {

                    int h1 = (bs + 1) * sq;
                    int ind1 = bs * sq;
                    mini[bs] = INT_MAX;
                    maxi[bs] = INT_MIN;
                    for (int j = ind1; j < h1; j++) {
                        if (j >= l)
                            diff[j] = diff[j] + x;
                        mini[bs] = min(mini[bs], diff[j]);
                        maxi[bs] = max(maxi[bs], diff[j]);
                    }

                    for (int k = bs + 1; k < be; k++)
                        temp[k] = temp[k] + x;

                    int h2 = min(n, (be + 1) * sq);
                    int ind2 = be * sq;
                    mini[be] = INT_MAX;
                    maxi[be] = INT_MIN;
                    for (int j = ind2; j < h2; j++) {
                        if (j <= r)
                            diff[j] = diff[j] + x;
                        mini[be] = min(mini[be], diff[j]);
                        maxi[be] = max(maxi[be], diff[j]);
                    }
                }
            }
            bool ok = false;

            for (int j = 0; j <= i / sq; j++) {
                if (mini[j] + temp[j] > 0 || maxi[j] + temp[j] < 0) continue;
                int h = min(n, (j + 1) * sq);
                int s = j * sq;
                for (int k = s; k < h; k++) {
                    if (k > i) break;
                    if (diff[k] + temp[j] == 0) {
                        ans = max(ans, i - k + 1);
                        ok = true;  
                        break;
                    }
                }
                if (ok)
                    break;
            }
        }
        return ans;
    }
};