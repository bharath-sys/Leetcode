class DSU {
private:
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n) {
        parent.resize(n, 0);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findPar(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = findPar(parent[x]);
    }

    void unionBySize(int a, int b) {
        int pa = findPar(a);
        int pb = findPar(b);
        if (pa == pb) {
            return;
        }
        if (size[pa] > size[pb]) {
            size[pa] += size[pb];
            parent[pb] = pa;
        } else {
            size[pb] += size[pa];
            parent[pa] = pb;
        }
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> nodes;
        for (int i = 0; i < points.size(); i++) {
            for (int j = 0; j < points.size(); j++) {
                if (i != j) {
                    int distance = abs(points[i][0] - points[j][0]) +
                                   abs(points[i][1] - points[j][1]);
                    nodes.push_back({distance, i, j});
                }
            }
        }

        sort(nodes.begin(),nodes.end());
        DSU d = DSU(points.size());
        int cost = 0;
        for(int i=0;i<nodes.size();i++){
            if(d.findPar(nodes[i][1])!=d.findPar(nodes[i][2])){
                cost+=nodes[i][0];
                d.unionBySize(nodes[i][1],nodes[i][2]);
            }
        }
        return cost;
    }
};