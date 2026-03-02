class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>has;
        int n = nums.size();
        for(int i = 0; i<n;i++){
            has[nums[i]]++;
        }
        for(auto it:has){
        if (it.second > (n/2)){
        return it.first;
        }
        }return -1;
    }
};