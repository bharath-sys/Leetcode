class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> st;
        vector<int> ans(t.size(),0);
        for(int i=t.size()-1;i>=0;i--){
            while(st.size() && t[i]>=t[st.top()])st.pop();
            ans[i] = st.size() ? st.top()-i : 0;
            st.push(i);
        }
        return ans;
    }
};