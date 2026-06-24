class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int ans = 0;
        for(auto cost:costs){
            if(coins>=cost){
                coins-=cost;
                ans+=1;
            }
            else {
                return ans;
            }
        }
        return costs.size();
    }
};