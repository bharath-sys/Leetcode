class Solution {
public:
    vector<vector<int>> memo;
    bool solve(vector<int>& nums, int idx, int remaining) {
        if (remaining == 0)
            return true;
        else if (idx >= nums.size())
            return false;
        if (memo[idx][remaining] != -1)
            return bool(memo[idx][remaining]);
        bool take = false;
        if (nums[idx] <= remaining) {
            return memo[idx][remaining] =
                       solve(nums, idx + 1, remaining - nums[idx]) ||
                       solve(nums, idx + 1, remaining);
        } else
            return memo[idx][remaining] = false;
    }
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2)
            return false;
        sort(nums.begin(), nums.end());
        // check if even sum of total/2 is possible
        memo.resize(nums.size(), vector<int>((total / 2) + 1, -1));
        return solve(nums, 0, total / 2);
    }
};