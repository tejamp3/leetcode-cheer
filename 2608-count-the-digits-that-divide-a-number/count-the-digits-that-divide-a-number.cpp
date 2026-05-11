class Solution {
public:
    int countDigits(int num) {
       int count = 0;
       int n = num;
        while (n>0){
          int k = n%10;
           if(k!=0&& num%k==0){
            count++;
           }
        n = n/10;

        }
        return count;
    }
};