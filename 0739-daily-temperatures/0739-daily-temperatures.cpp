class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
      vector<int> ans(t.size(),0);
      stack<int> st;
      for(int i=t.size()-1;i>=0;i--){
        while(st.size() && t[st.top()]<=t[i])st.pop();
        if(st.size())ans[i] = st.top()-i;
        st.push(i);
      } 
      return ans;
    }
};