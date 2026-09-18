class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int suff = 1;int pref = 1;int ans = INT_MIN;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(pref == 0)pref = 1;
            if(suff == 0)suff = 1;
            pref = pref*nums[i];
            suff = suff*nums[n-1-i];
            int maxi = max(max(nums[i],pref),max(nums[n-1-i],suff));
            ans = max(ans,maxi);
        }
        return ans;
    }   
};