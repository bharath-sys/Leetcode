class Solution {
public:

    long long countFairPairs(vector<int>& ll, int l, int u) {
        long long ans = 0;
        sort(ll.begin(),ll.end());
        auto start = ll.begin();
        for(int i=1;i<ll.size();i++){
            auto lb = lower_bound(start,start+i,l-ll[i]);
            auto ub = upper_bound(start,start+i,u-ll[i])-1;
            if(ub>=lb){
                ans+=ub-lb+1;
            }
        }
        return ans;
    }
};