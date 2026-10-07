class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for (int i = 1; i < nums.size(); i++) {
            auto lb = lower_bound(nums.begin(), nums.begin() + i,lower - nums[i]);
            auto ub = upper_bound(nums.begin(), nums.begin() + i,upper - nums[i]);
            ans += ub - lb;
        }
        return ans;
    }
};