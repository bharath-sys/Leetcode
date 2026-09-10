class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int rSum=0;int ways = 0;
        for(int i=0;i<nums.size();i++){
            rSum+=nums[i];
            if(mp.find(rSum-k)!=mp.end()){
                ways+=mp[rSum-k];
            }
            mp[rSum]+=1;
        }
        return ways;
    }
};