class Solution {
public:
    vector<vector<int>> dp;
    bool isSumPossible(int target,vector<int> &nums,int idx){
        if(target==0) return true;
        if(idx>=nums.size())return false;
        if(dp[target][idx]!=-1)return bool(dp[target][idx]);
        if(target>=nums[idx]){
            return dp[target][idx] = (isSumPossible(target-nums[idx],nums,idx+1) || isSumPossible(target,nums,idx+1));
        }
        else return dp[target][idx] = false;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0)return false;
        sort(nums.begin(),nums.end());
        dp.resize((sum/2)+1,vector<int>(nums.size(),-1));
        return isSumPossible(sum/2,nums,0);
    }
};