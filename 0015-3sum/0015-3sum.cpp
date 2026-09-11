class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++){
            while(i>0 && i<nums.size() && nums[i]==nums[i-1])i++;
            int j=i+1;int k=nums.size()-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum==0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j+=1;k-=1;
                }
                else if(sum>0){
                    k-=1;
                }
                else j+=1;
                while(j>i+1 && j<k && nums[j]==nums[j-1])j++;
                while(k<nums.size()-1 && k>j && nums[k]==nums[k+1])k--;
            }
        }
        return ans;
    }
};