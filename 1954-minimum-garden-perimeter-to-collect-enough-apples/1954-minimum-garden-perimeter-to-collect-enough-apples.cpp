typedef long long ll;
class Solution {
public:
    long long countApples(long long n){
        long long apples = 2*(n*(n+1)*(2*n+1));
        return apples;
    }
    long long minimumPerimeter(long long neededApples) {
        ll l = 1;
        ll r = 100'000LL;
        while(l<=r){
            ll m = l+(r-l)/2;
            if(countApples(m)>=neededApples){
                r=m-1;
            }
            else l=m+1;
        }
        cout<<"index i : "<<l<<endl;
        cout<<"count of apples : "<<countApples(l);
        return 8*l;
    }
};