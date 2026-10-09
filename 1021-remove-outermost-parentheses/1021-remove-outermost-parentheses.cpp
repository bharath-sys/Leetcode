class Solution {
public:
    string removeOuterParentheses(string s) {
        int b=0;
        string ans = "";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                b++;
                if(b>1)ans.push_back(s[i]);
            }
            else {
                b--;
                if(b>0)ans.push_back(s[i]);
            }
        }
        return ans;
    }
};