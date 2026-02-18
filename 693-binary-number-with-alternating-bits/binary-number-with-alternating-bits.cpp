class Solution {
public:
    bool hasAlternatingBits(int n) {
        int c=n&1;
        n>>=1;
        while(n>0)
        {
            int d=n&1;
            if(d==c)
            {
                return false;
            }
            else{
                c=d;
                n>>=1;
            }
        }
        return true;
    }
};