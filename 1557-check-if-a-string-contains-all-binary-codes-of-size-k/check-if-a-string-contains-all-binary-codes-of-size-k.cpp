class Solution {
public:
    //TC = O(n * k)   &&   SC = O(n)
    bool hasAllCodes(string s, int k) {
        int n = s.size();

        unordered_set<string> st;

        int codes = pow(2, k); //1<<k

        for(int i = k; i <= n; i++) {
            string sub = s.substr(i-k, k);

            if(!st.count(sub)) {
                st.insert(sub);
                codes--;
            }

            if(codes == 0) {
                return true;
            }
        }

        return false;
    }
};