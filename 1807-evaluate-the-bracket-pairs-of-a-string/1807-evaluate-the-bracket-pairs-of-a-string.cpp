class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;
        for(auto row:knowledge){
            mp[row[0]] = row[1];
        }
        int i=0;
        string ans;
        while(i<s.length()){
            if(s[i]=='('){
                string key="";
                while(s[++i]!=')'){
                    key.push_back(s[i]);
                }
                i++;
                if(mp.find(key)!=mp.end())ans+=mp[key];
                else ans.push_back('?');
            }
            else ans.push_back(s[i++]);
        }
        return ans;
    }
};