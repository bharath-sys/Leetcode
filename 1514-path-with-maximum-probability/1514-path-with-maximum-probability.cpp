class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start_node,
                          int end_node) {

        vector<vector<pair<int, double>>> adj(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back({v, succProb[i]});
            adj[v].push_back({u, succProb[i]});
        }
        vector<bool> visited(n, false);
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});
        while (!pq.empty()) {
            auto [prob, node] = pq.top();
            pq.pop();
            if (visited[node])
                continue;
            visited[node] = true;
            if (node == end_node)
                return prob;
            for (auto [next, edgeProb] : adj[node]) {
                if (!visited[next]) {
                    pq.push({prob * edgeProb, next});
                }
            }
        }

        return 0.0;
    }
};