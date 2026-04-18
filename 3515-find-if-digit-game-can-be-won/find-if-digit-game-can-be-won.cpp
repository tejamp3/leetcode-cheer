class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        vector<int> c;
        vector<int> d;

        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(nums[i] > 9){
                c.push_back(nums[i]);
            } else {
                d.push_back(nums[i]);
            }
        }

        if(accumulate(d.begin(), d.end(), 0) == accumulate(c.begin(), c.end(), 0))
            return false;
        else
            return true;
    }
};