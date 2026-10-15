class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            vector<int> seen(101,0);
            int unq = 0;
            for(int j=i;j<nums.size();j++){
                if(seen[nums[j]]==0){
                    unq++;seen[nums[j]]=1;
                }
                ans+=(unq*unq);
            }
        }
        return ans;
    }
};