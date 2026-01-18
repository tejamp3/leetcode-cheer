#include<bits/stdc++.h>
using namespace std; 

class Solution {
public: 
    string findRecursive(
        const unordered_set<string>& nums_set, 
        string current_s,                          
        int n)                                          
    {
        if (current_s.length() == n) {
            if (nums_set.find(current_s) == nums_set.end()) {
                return current_s;
            }
            return "";
        }

        string result_from_zero = findRecursive(nums_set, current_s + '0', n);

        if (!result_from_zero.empty()) {
            return result_from_zero;
        }

        string result_from_one = findRecursive(nums_set, current_s + '1', n);

        return result_from_one;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();

        unordered_set<string> nums_set(nums.begin(), nums.end());

        return findRecursive(nums_set, "", n);
    }
};
