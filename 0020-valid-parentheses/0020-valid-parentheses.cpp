class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> mp;
        mp['}'] = '{';
        mp[')'] = '(';
        mp[']'] = '[';
        stack<char> st;
        for(char c:s){
            if(c=='(' || c=='{' || c=='['){
                st.push(c);
            }
            else {
                if(st.size() && st.top()==mp[c])st.pop();
                else return false;
            }
        }
        return st.empty();
    }
};