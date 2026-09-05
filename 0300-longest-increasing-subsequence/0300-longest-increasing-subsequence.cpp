class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> lis;
        lis.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            // find lowerbound
            int lb = lower_bound(lis.begin(),lis.end(),nums[i])-lis.begin();
            if(lb==lis.size()){
                lis.push_back(nums[i]);
            }
            else {
                lis[lb] = nums[i];
            }
        }
        return lis.size();
    }
};

