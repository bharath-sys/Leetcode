class Solution {
public:
     int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = 0;int l = 0;int r = n-1;int mod = 1e9+7;
        int* pows = new int[n];
        pows[0] = 1;
        for(int i=1;i<n;i++){
            pows[i] = (pows[i-1]*2)%mod;
        }
        while(l<=r){
            if(nums[l]+nums[r]>target){
                r-=1;
            }
            else{
                ans = (ans + pows[(2,(r-l++))])%mod;
            }
        }
        return ans;
    }
};