class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        int cost = 0;
        int mini = nums[0];
        int prof = 0;
        for(int i=0;i<n;i++){
            cost = nums[i]-mini;
            prof = max(prof , cost);
            mini = min(mini,nums[i]);
            
        }return prof;
    }
};