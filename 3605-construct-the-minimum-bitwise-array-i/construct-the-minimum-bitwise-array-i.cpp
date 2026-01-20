class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
            if(nums[i]==2)ans[i]=-1;
            else
            {
                for(int j=0;j<10;j++)
                {
                    int num = 1<<j;
                    int res = nums[i]&num;
                    if(res==0)
                    {
                        int m = 1<<(j-1);
                        ans[i] = nums[i]^m;
                        break;
                    }

                }
            }
        }
        return ans;
    }
};