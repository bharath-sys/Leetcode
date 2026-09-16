class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2)return nums.size();
        int i,j;i=j=2;
        while(i<nums.size()){
            if(nums[i]==nums[j-2])i++;
            else {
                nums[j++]=nums[i++];
            }
        }
        return j;
    }
};