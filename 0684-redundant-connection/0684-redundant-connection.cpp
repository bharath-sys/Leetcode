class DSU {
    vector<int> size,parent;
public:
    DSU(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)parent[i]=i;
    }
    
    int findPar(int x){
        if(parent[x]==x)return x;
        return parent[x] = findPar(parent[x]);
    }

    void unionBySize(int a,int b){
        a = findPar(a);b = findPar(b);
        if(a==b)return;
        if(size[a]<size[b]){
            parent[a]=b;
            size[b]+=size[a];
        }
        else{
            parent[b]=a;
            size[a]+=size[b];
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU ds(n);
        for(auto edge:edges){
            int a = edge[0]; int b = edge[1];
            if(ds.findPar(a)==ds.findPar(b)){
                return {a,b};
            }
            ds.unionBySize(a,b);
        }
        return {0,0};
    }
};