class Solution {
public:
    string makeLargestSpecial(string s) {
        while(true)
        {
            bool check=false;
            for(int i=0;i<s.size();i++)
            {
                int cnt=0;
                string ss;
                for(int j=(i+1);j<s.size();j+=2)
                {
                    cnt+=((s[j-1]=='1')-(s[j-1]=='0'));
                    if(cnt<0) break;
                    cnt+=((s[j]=='1')-(s[j]=='0'));
                    if(cnt<0) break;
                    ss.push_back(s[j-1]);
                    ss.push_back(s[j]);
                    if(!cnt)
                    {
                        int pos=0,save=ss.size();
                        string sss;
                        int cntt=0;
                        for(int k=(j+2);k<s.size();k+=2)
                        {
                            cntt+=((s[k-1]=='1')-(s[k-1]=='0'));
                            if(cntt<0) break;
                            cntt+=((s[k]=='1')-(s[k]=='0'));
                            if(cntt<0) break;
                            sss.push_back(s[k-1]);
                            sss.push_back(s[k]);
                            if(sss.size()>ss.size())
                            {
                                ss.push_back(ss[pos]);
                                ss.push_back(ss[pos+1]);
                                pos+=2;
                                if(pos==save) pos=0;
                            }
                            if(!cntt && sss>ss)
                            {
                                check=true;
                                for(int h=i;h<(i+sss.size());h++) s[h]=sss[h-i];
                                for(int h=(i+sss.size());h<(i+sss.size()+save);h++)
                                {
                                    s[h]=ss[h-i-sss.size()];
                                }
                                break;
                            }
                        }
                        if(!check)
                        {
                            while(ss.size()>save) ss.pop_back();
                        }
                    }
                    if(check) break;
                }
                if(check) break;
            }
            if(!check) break;
        }
        return s;
    }
};