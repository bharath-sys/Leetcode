class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int overlapping = 0;
        sort(intervals.begin(),intervals.end());
        int i=0;
        for(int j=1;j<intervals.size();j++){
            if(intervals[j][0]<intervals[i][1]){
                overlapping+=1;
                intervals[i][1] = min(intervals[i][1],intervals[j][1]);
            }
            else{
                i=j;
            }
        }
        return overlapping;
    }
};