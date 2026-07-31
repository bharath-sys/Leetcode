class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        vector<int> mp(26,0);
        int chars = 0;
        for(char ch:word){
            mp[ch-'a']+=1;
        }
        sort(mp.begin(), mp.end(), greater<int>());
        int mulFactor = 1;
        for(int cnt:mp){
            if(cnt){
                chars+=1;
                ans+=(mulFactor*cnt);
            }
            if(chars==8){
                mulFactor+=1;
                chars = 0;
            }
        }
        return ans;
    }
};