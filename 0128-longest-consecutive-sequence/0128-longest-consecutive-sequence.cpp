class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int ans = 0;
        for(int num:s){
            if(s.count(num+1)==0){
                int x=num;
                int len = 1;
                while(s.count(x-1)){
                    x-=1;
                    len+=1;
                }
                ans = max(ans,len);
            }
        }
        return ans;
    }
};