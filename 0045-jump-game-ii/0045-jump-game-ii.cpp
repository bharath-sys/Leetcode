class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> minSteps(nums.size(),1e4+1);
        minSteps[nums.size()-1] = 0;
        for(int i=nums.size()-2;i>=0;i--){
            for(int j=nums[i];j>=1;j--){
                if(i+j>=nums.size()-1){minSteps[i] = 1;break;}
                else minSteps[i] = min(1+minSteps[i+j],minSteps[i]);
            }
        }
        return minSteps[0];
    }
};