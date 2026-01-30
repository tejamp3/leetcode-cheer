class Solution {
public:
    bool checkZeroOnes(string s) {
        int n =s.size();
        int o=0,z=0;
        int ma=0,pa = 0;
        for(int i = 0;i<n;i++){
            if(s[i]=='1'){
            o=o+1;
            ma = max(ma,o);}
            else
            o = 0;
            }
            for(int i = 0;i<n;i++){
            if(s[i]=='0'){
            z=z+1;
            pa = max(pa,z);}
            else
            z = 0;
            }
            if(ma>pa)
            return true;
            if (pa>=ma)
            return false;
            else return 0;
    }
};