class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int ans = 1;int j = 0;
        for(int i=1;i<points.size();i++){
            if(points[i][0]<=points[j][1]){
                points[j][1] = min(points[j][1],points[i][1]);
            }
            else {
                ans++;
                points[++j] = points[i];
            }
        }
        return ans;
    }
};