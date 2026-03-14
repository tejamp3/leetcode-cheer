    #include <bits/stdc++.h>
    using namespace std;

    class Solution {
    public:
        string getHappyString(int n, int k) {
            string res = "";
            int totalHappyString = 3 * (1<<(n-1));
            if(k>totalHappyString){
                return res;
            }

            int pos = 0;
            int N = n;
            while (res.size()!=N)
            {
                if(res.empty()){
                    int startingWithA = (1<<(n-1));
                    int startingWithB = startingWithA + (1<<(n-1));
                    int startingWithC = startingWithB + (1<<(n-1));
                    if(k<=startingWithA){
                        res.push_back('a');
                    }

                    else if(k<=startingWithB){
                        res.push_back('b');
                        k-=startingWithA;
                    }

                    else{
                        res.push_back('c');
                        k-=startingWithB;
                }

             }

             else if(res.back() == 'a'){
                int startingWithB =  (1<<(n-1));
                int startingWithC = startingWithB + (1<<(n-1));

                if(k<=startingWithB){
                    res.push_back('b');
                }
                else{
                    res.push_back('c');
                    k-=startingWithB;
                }
             }

             else if(res.back() == 'b'){
                int startingWithA =  (1<<(n-1));
                int startingWithC = startingWithA + (1<<(n-1));

                if(k<=startingWithA){
                    res.push_back('a');
                }
                else{
                    res.push_back('c');
                    k-= startingWithA;
                }

             }

             else if(res.back() == 'c'){
                int startingWithA =  (1<<(n-1));
                int startingWithB = startingWithA + (1<<(n-1));

                if(k<=startingWithA){
                    res.push_back('a');
                }
                else{
                    res.push_back('b');
                    k-= startingWithA;
                }
             }
                
                n--;
            }

            return res;
            
        }
    };