class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int global = abs(nums[0]);
        int localmaxi = nums[0];
        int localmini = nums[0];
        for(int i=1;i<nums.size();i++){
            localmaxi = max(nums[i],localmaxi+nums[i]);
            localmini = min(nums[i],localmini+nums[i]);
            global = max(global,max(localmaxi,abs(localmini)));
        }
        return global;
    }
};