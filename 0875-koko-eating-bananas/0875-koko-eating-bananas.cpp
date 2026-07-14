class Solution {
public:
    bool kokoCanEat(int speed,vector<int>& piles, int hours){
        long eatingTime = 0;
        for(int pile:piles){
            int pileTime = pile%speed ? pile/speed+1 : pile/speed;
            eatingTime+=pileTime;
        }
        return eatingTime<=hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());
        int ans = INT_MAX;
        while(l<=r){
            int m = l+(r-l)/2;
            if(kokoCanEat(m,piles,h)){
                ans = min(ans,m);
                r = m-1;
            }
            else l = m+1;
        }
        return ans;
    }
};