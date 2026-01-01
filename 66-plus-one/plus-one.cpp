class Solution {
public:
    vector<int> plusOne(vector<int>& dig) {
        reverse(dig.begin(), dig.end());
        int i = 0;
        int n = dig.size();
        
        if (dig[i] != 9) dig[i]++;
        else {
            while (dig[i] >= 9) {
                dig[i] = 0;
                if (i + 1 == n) dig.push_back(1);
                else {
                    i++;
                    dig[i]++;
                    if (dig[i] == 9) break;
                }
            }
        }

        reverse(dig.begin(), dig.end());
        return dig;
    }
};