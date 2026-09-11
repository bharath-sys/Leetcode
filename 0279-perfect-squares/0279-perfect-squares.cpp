class Solution {
public:
    vector<int> memo;
    int solve(vector<int>& nums, int target) {
        if (target == 0) {
            return 0;
        }
        if(memo[target]!=-1)return memo[target];
        int ans = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (target - nums[i] >= 0) {
                int take = solve(nums, target - nums[i]);
                if (take != INT_MAX) {
                    ans = min(ans,1+take);
                }
            }
        }
        return memo[target] = ans;
    }
    int numSquares(int n) {
        vector<int> nums;
        for (int i = 1; i <= sqrt(n); i++) {
            nums.push_back(i * i);
        }
        memo.resize(n+1,-1);
        return solve(nums, n);
    }
};