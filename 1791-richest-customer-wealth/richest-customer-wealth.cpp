class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n = accounts.size();
        vector<int> arr(n);
        
        for (int i = 0; i < n; i++) {
        
            arr[i] = accumulate(accounts[i].begin(), accounts[i].end(), 0);
        } 
        
        return *max_element(arr.begin(), arr.end());
    } 
}; 
