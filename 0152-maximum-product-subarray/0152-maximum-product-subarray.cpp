class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = 1;
        int mini = 1;
        int ans = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int oldMaxi=maxi;
            maxi = max(max(nums[i] * maxi, nums[i]), nums[i] * mini);
            mini = min(min(nums[i] * mini, nums[i]), nums[i] * oldMaxi);
            ans = max(maxi, ans);
        }
        return ans;
    }
};