class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());

        vector<long long> ans(n);
        int i = 0;

        while (i < n) {
            int j = i;
            long long total = 0;

            while (j < n && arr[j].first == arr[i].first) {
                total += arr[j].second;
                j++;
            }

            int size = j - i;
            long long prefix = 0;

            for (int k = 0; k < size; k++) {
                long long idx = arr[i + k].second;

                long long left = k * idx - prefix;
                long long right = (total - prefix - idx) - (long long)(size - k - 1) * idx;

                ans[idx] = left + right;
                prefix += idx;
            }

            i = j;
        }

        return ans;
    }
};