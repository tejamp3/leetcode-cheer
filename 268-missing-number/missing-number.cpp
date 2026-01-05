class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        int k,l;
        for(int i = 0;i<nums.size();i++){
            sum +=nums[i];
        }
        k = n*(n+1)/2;
        l=k-sum;

    return l;
    }
};