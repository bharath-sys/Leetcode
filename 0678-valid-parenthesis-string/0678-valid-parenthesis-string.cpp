class Solution {
public:
    bool checkValidString(string s) {
        int l = 0, h = 0;
        for (auto& c : s) {
            if(c=='('){
                l++;h++;
            }
            else if(c==')'){
                l--;h--;
            }
            else {
                l--;h++;
            }
            if (h < 0) return 0;
            l = max(l, 0);
        }
        return l == 0;
    }
};