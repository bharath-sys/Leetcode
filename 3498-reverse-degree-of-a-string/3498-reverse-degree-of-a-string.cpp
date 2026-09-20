class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;int i =0;
        for(char ch:s){
            int index = int(ch-'a');
            ans+=(26-index)*(i+1);
            i++;
        }
        return ans;
    }
};