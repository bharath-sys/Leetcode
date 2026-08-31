class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int prev2 = nums[0];
        int prev1 = max(nums[1],prev2);
        for (int i = 2; i < nums.size(); i++) {
            int temp = prev1;
            prev1 = max(nums[i]+prev2,prev1);
            prev2 = temp;
        }
        return max(prev1,prev2);
    }
};