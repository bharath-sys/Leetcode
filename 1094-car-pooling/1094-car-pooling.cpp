class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> nums(1001,0);
        for(int i=0;i<trips.size();i++){
            for(int j=trips[i][1];j<trips[i][2];j++){
                if(nums[j]+trips[i][0]>capacity)return false;
                nums[j]+=trips[i][0];
            }
        }
        return true;
    }
};