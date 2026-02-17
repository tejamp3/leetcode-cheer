class Solution {
public:
    vector<string> readBinaryWatch(int t) {
        if(t==0)return{"0:00"};
        if(t>8) return {};
        vector<string>p;
        for(int i=0;i<12;i++){
            for(int j=0;j<60;j++){
                int h=popcount((unsigned int)i);
                int m=popcount((unsigned int)j);
                if(h+m==t){
                    string s=to_string(i)+":";
                    if(j<10){
                        s+="0";
                    }
                        s+=to_string(j);
                        p.push_back(s);
                }
            }
        }

        return p;
    }
};