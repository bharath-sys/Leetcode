class FindSumPairs {
private: 
    vector<int> A,B;
    unordered_map<int,int> mp;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        A.assign(nums1.begin(),nums1.end());
        B.assign(nums2.begin(),nums2.end());
        for(int num:B)mp[num]+=1;
    }
    
    void add(int index, int val) {
        if(index<0 || index>B.size()-1) return;
        mp[B[index]]-=1;
        B[index]+=val;
        mp[B[index]]+=1;
    }
    
    int count(int tot) {
        int ans = 0;
        for(int i=0;i<A.size();i++){
            // if(i>0 && A[i]==A[i-1])continue;
            ans+=(mp[tot-A[i]]);
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */