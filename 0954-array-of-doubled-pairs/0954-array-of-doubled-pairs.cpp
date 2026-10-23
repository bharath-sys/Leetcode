class Solution {
public:
    struct cmp {
        bool operator()(const int a,const int b){
            if(a<0 && b<0)return a>b;
            return a<b;
        }
    };
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto x:arr)mp[x]++;
        sort(arr.begin(),arr.end(),cmp());
        for(int i=0;i<arr.size();i++){
            if(mp[arr[i]]==0)continue;
            int twice = 2*arr[i];
            if(!(mp[twice]>0))return false;
            mp[twice]-=1;
            mp[arr[i]]-=1;
        }
        return true;
    }
};