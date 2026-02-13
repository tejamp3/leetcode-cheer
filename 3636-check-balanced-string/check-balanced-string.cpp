class Solution {
public:
    bool isBalanced(string num) {
        
        int n=num.size();
        int even=0;
        int odd=0;
        for(int i=0;i<n;i+=2){
             even+=num[i]-'0';


        }for(int i=1;i<n;i+=2){
            odd += num[i]-'0';


         }if (even == odd)
            return true;
         else if(even!=odd)
            return false;
        else return 0;
         
        

    }
};