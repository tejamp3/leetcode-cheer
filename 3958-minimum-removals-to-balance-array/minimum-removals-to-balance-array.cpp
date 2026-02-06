class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        //sort so that we have min an dmax values next to eachother to get sliding window 
        sort(nums.begin(),nums.end());
        int n=nums.size();
        //use 2 pointer approach 
        //after sorting nums[i] is minimum and nums[j] is maximm in that wondow
        //expand j  till given condition satisfies that is nums[j]<=k*nums[i]
        int result=n;
        for(int left=0,right=0; right<n;)
        {
            //check condition if satisfies 
            if((long long)nums[left]*k>=nums[right])  //convert to long 
            {
                //if yes: store ans and move to expand by adding next ele to window
                result=min(result, n-right+left-1);
                right++; 

            }
            else
            {
                //remove that elemnet that is eliminatong the let ele and move to next
                left++;
            }
        }
        return result;
        
    }
};