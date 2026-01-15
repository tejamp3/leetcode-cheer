class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int max1 = 1, count1 = 1;
        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] - hBars[i-1] == 1) {
                count1++;
            } else {
                max1 = max(max1, count1);
                count1 = 1;
            }
        }
        max1 = max(max1, count1);

        int max2 = 1, count2 = 1;
        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i] - vBars[i-1] == 1) {
                count2++;
            } else {
                max2 = max(max2, count2);
                count2 = 1;
            }
        }
        max2 = max(max2, count2);

        int side = min(max1, max2)+1;
        return side * side;
    }
};