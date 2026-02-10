class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int l = 0;
        for (int i = 0; i < nums.size(); i++) {
                // vector<int> even;
                // vector<int> odd;
                unordered_set<int> even;
                unordered_set<int> odd;
            for (int j = i; j < nums.size(); j++) {
                if(nums[j]%2==0){
                    even.insert(nums[j]);
                }
                else{
                    odd.insert(nums[j]);
                }
                // sort(even.begin(),even.end()); 
                // sort(odd.begin(),odd.end()); 

                // even.erase(unique(even.begin(),even.end()),even.end());
                // odd.erase(unique(odd.begin(),odd.end()),odd.end());
                if(even.size()==odd.size()){
                    l = max(l,j-i+1);
                }
            }
        }
        return l;
    }
};