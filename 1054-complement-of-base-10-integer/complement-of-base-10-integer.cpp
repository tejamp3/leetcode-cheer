class Solution {
    // tc- O(log(n))
public:
    int bitwiseComplement(int n) {
        if(n<=0) return 1;
        int digit =0;
        int temp=n;
        while(temp>0){
            digit++;
            temp = temp >> 1;
        }
        int maxNum = (1<< digit)-1;
        return n ^ maxNum;
    }
};