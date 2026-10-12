class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        while(i<nums.size()){
            if(nums[i]<=0)i++;
            else if(nums[i] < nums.size() && nums[i]!=i+1){
                if(nums[nums[i]-1]==nums[i])i++;
                else swap(nums[i],nums[nums[i]-1]);
            }
            else i++;
        }
        int counter = 1;
        for(int i=0;i<nums.size();i++,counter++){
            if(nums[i]!=i+1)return i+1;
        }
        return counter;
    }
};