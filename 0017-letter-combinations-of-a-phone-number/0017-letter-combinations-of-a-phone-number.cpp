class Solution {
public:
    void solve(string d,vector<string> &ans,map<int,string> kb,int i,string temp){
        if(i==d.length()){
            ans.push_back(temp);
            return;
        }
        for(char x:kb[d[i]]){
            solve(d,ans,kb,i+1,temp+x);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0 ) return {};
        map<int,string> keyBoard;
        keyBoard['2'] = "abc";
        keyBoard['3'] = "def";
        keyBoard['4'] = "ghi";
        keyBoard['5'] = "jkl";
        keyBoard['6'] = "mno";
        keyBoard['7'] = "pqrs";
        keyBoard['8'] = "tuv";
        keyBoard['9'] = "wxyz";
        vector<string> ans;
        solve(digits,ans,keyBoard,0,"");
        return ans;
    }
};