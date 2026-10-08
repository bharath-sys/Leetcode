class Solution {
public:
    string removeOuterParentheses(string s) {
        int b=0;
        string ans = "";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                b++;
            }
            else {
                b--;
            }
            if(i!=0 && b>0 && !(s[i]=='(' && b==1))ans.push_back(s[i]);
        }
        return ans;
    }
};