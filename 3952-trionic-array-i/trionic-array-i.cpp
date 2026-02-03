class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i=0;
        while(i+1<nums.size()&&nums[i+1]>nums[i])
        i++;
        if(i==0||i==nums.size()-1)
        return false;
        while(i+1<nums.size()&&nums[i+1]<nums[i])
        i++;
        if(i==nums.size()-1)
        return false;
        while(i+1<nums.size()&&nums[i+1]>nums[i])
        i++;
        return i==nums.size()-1;
    }
};