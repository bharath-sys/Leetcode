class Solution {
public:
    int custom_lower_bound(vector<int> &nums,int ele){
        int l,r;
        l = 0; r = nums.size()-1;
        int lb = nums.size();
        while(l<=r){
            int m = l+(r-l)/2;
            if(nums[m]<ele){
                l = m+1;
            }
            else {
                lb = m;
                r = m-1;
            }
        }
        return lb;
    }
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> lis;
        lis.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            // find lowerbound
            // int lb = lower_bound(lis.begin(),lis.end(),nums[i])-lis.begin();
            int lb = custom_lower_bound(lis,nums[i]);
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

