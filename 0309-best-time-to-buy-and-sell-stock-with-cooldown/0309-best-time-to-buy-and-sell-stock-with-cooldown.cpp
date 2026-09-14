class Solution {
public:
    vector<vector<int>> memo;
    int solve(vector<int>& prices,int idx,bool canBuy){
        if(idx>=prices.size())return 0;
        if(memo[idx][int(canBuy)]!=-1)return memo[idx][int(canBuy)];
        int buy = 0;
        int sell = 0;
        if(canBuy){
            buy = max(-prices[idx]+solve(prices,idx+1,false),solve(prices,idx+1,true));
        }
        else {
            sell = max(prices[idx]+solve(prices,idx+2,true),solve(prices,idx+1,false));
        }
        return memo[idx][int(canBuy)] = max(buy,sell);
    }
    int maxProfit(vector<int>& prices) {
        memo.resize(prices.size(),vector<int> (2,-1));
        return solve(prices,0,true);
    }
};