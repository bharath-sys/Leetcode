class Solution {
public:
    int solve(vector<int> &nums,int start,int end){
        if(end-start+1==2)return max(nums[start],nums[end]); 
        vector<int> dp(end+1,0);
        dp[start] = nums[start];
        dp[start+1] = max(nums[start],nums[start+1]);
        for(int i=start+2;i<=end;i++){
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        return max(dp[end],dp[end-1]);
    }
    int rob(vector<int>& nums) {
       if(nums.size()==1)return nums[0];
       else if(nums.size()==2) return max(nums[0],nums[1]);
       return max(solve(nums,0,nums.size()-2),solve(nums,1,nums.size()-1)); 
    }
};