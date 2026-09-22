class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> nums(1001,0);
        for(int i=0;i<trips.size();i++){
            nums[trips[i][1]]+=trips[i][0];nums[trips[i][2]]-=trips[i][0];
        }
        int load = 0;
        for(auto x:nums){
            load+=x;
            if(load>capacity)return false;
        }
        return true;
    }
};