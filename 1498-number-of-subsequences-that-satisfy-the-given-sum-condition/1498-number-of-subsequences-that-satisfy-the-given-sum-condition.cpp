class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums.size() - 1;
        long long ans = 0;
        int mod = 1e9 + 7;
        vector<long long> power(nums.size() + 1, 1);

        for (int i = 1; i <= nums.size(); i++) {
            power[i] = (power[i - 1] * 2) % mod;
        }

        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                ans+=power[r-l];
                ans%=mod;
                l++;
            } else
                r -= 1;
        }
        return ans % mod;
    }
};