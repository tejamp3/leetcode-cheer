/**
 * @param s binary string
 * @return number of steps
 */
class Solution {
public:
    int numSteps(string s) {
        int steps = 0;

        while (s.length() > 1) {
            if (s.back() == '0') {
                // even → divide by 2
                s.pop_back();
            } else {
                // odd → add 1 (handle carry)
                int i = s.length() - 1;
                while (i >= 0 && s[i] == '1') {
                    s[i] = '0';
                    i--;
                }
                if (i >= 0) {
                    s[i] = '1';
                } else {
                    s = '1' + s;
                }
            }
            steps++;
        }

        return steps;
    }
};