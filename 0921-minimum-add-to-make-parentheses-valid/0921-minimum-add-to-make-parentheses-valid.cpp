class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int closedLeft = 0;
        for(char ch:s){
            if(ch=='(')st.push(ch);
            else{
                if(st.size() && st.top()=='(')st.pop();
                else closedLeft++;
            }
        }
        return st.size()+closedLeft;
    }
};