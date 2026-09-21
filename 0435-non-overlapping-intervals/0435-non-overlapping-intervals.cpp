class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        int ans = 0;
        sort(arr.begin(),arr.end());
        int j=0;
        for(int i=1;i<arr.size();i++){
            if(arr[i][0]<arr[j][1]){
                ans+=1;
                arr[j][1] = min(arr[i][1],arr[j][1]);
            }
            else {
                arr[++j] = arr[i]; 
            }
        }

        return ans;
    }
};