class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int ans = 0,currSum=0;
        for(int i=0;i<nums.size();i++){
            currSum+=nums[i];
            int complement = currSum-k;
            if(mp.find(complement)!=mp.end()){
                ans+=mp[complement];
            }
            mp[currSum]+=1;
        }
        return ans;
    }
};