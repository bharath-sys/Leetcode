class Solution {
public:
    int minInsertions(string s) {
        int o, i;
        o = i = 0;
        int ans = 0;
        while (i < s.length()) {
            if (s[i] == '(') {
                o += 1;
            } else {
                if (i + 1 < s.length() && s[i + 1] == ')') {
                    i++;
                } else {
                    ans++;
                }
                if (o == 0) {
                    ans++;
                } else {
                    o--;
                }
            }
            i++;
        }
        return ans + 2 * o;
    }
};