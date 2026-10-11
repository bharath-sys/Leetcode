typedef long long ll;
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        ll prod = 1;
        int ans = 0;
        for(int i=0,j=0;i<=j && j<nums.size();j++){
            prod*=nums[j];
            while(i<=j && prod>=1LL*k) {
                prod/=nums[i++];
            }
            if(prod<1LL*k){
                ans+=j-i+1;
            }
        }
        return ans;
    }
};