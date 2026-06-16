class Solution {
public:
    bool checkGoodInteger(int n) {
        int sq =0;
        int di =0;
        while (n>0){
            di+= n%10;
            sq+=(n%10)*(n%10);
            n/=10;
        }
        if((sq-di)>=50){
        return true;
        }
        else
        return false;
    }
};