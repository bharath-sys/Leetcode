class Solution {
public:
    int findMin(vector<int>& nums) {
        /* 
        l m-1 , m+1 r 
        find sorted end take minimum go to other side 
        */
        int l = 0,r = nums.size()-1;
        int mini = INT_MAX;
        while(l<=r){
            int m = l+(r-l)/2;
            // if left half sorted 
            if(nums[l]<=nums[m]){
                mini = min(mini,nums[l]);
                l=m+1;
            }
            else {
                mini = min(nums[m],mini);
                r = m-1;
            }
        }
        return mini;
    }
};