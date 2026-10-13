class Solution {
public:
    struct cmp {
        bool operator ()(const int a,const int b){
            return abs(a)<abs(b);
        }
    };
    long long maxAlternatingSum(vector<int>& nums) {
        int l,r;
        l = 0;r = nums.size()-1;
        sort(nums.begin(),nums.end(),cmp());
        long long ans = 0;
        while(l<=r){
            if(l==r)ans+=pow(nums[l++],2);
            else ans+=(pow(nums[r--],2)-pow(nums[l++],2));
        }
        return ans;
    }
};