class Solution {
public:
    int lower_bound(vector<vector<int>> &nums,int val){
        int l=0;int r=nums.size()-1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(nums[m][0]>=val)r = m-1;
            else l=m+1;
        }
        return l<nums.size() ? nums[l][1] : -1;
    }
    vector<int> findRightInterval(vector<vector<int>>& arr) {
        vector<vector<int>> nums;
        for (int i = 0; i < arr.size(); i++) {
            nums.push_back({arr[i][0], i});
        }
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for (int i = 0; i < arr.size(); i++) {
            int lb = lower_bound(nums,arr[i][1]);
            ans.push_back(lb);
        }
        return ans;
    }
};