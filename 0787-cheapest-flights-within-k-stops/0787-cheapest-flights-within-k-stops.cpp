class node {
public:
    int stop;
    int dist;
    int stops;
    node(int a, int b, int c) {
        stop = a;
        dist = b;
        stops = c;
    }
};
// struct cmp {
//     bool operator()(const node* a, const node* b) {
//         if (a->dist == b->dist) {
//             return a->stops > b->stops;
//         }
//         return a->dist > b->dist;
//     }
// };
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        queue<node*> pq;
        vector<vector<pair<int,int>>> adj(n);
        vector<int> prevDist(n,INT_MAX);
        for (auto flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        node* start = new node(src, 0, -1);
        pq.push(start);
        int ans = INT_MAX;
        while (pq.size()) {
            node* currFlight = pq.front();
            pq.pop();
            if (currFlight->stop == dst)
                ans = min(ans,currFlight->dist);
            if (currFlight->stops == k)
                continue;
            for (auto &[stop,dist] : adj[currFlight->stop]) {
                if (currFlight->stops <= k && prevDist[stop]>currFlight->dist + dist) {
                    prevDist[stop] = currFlight->dist + dist;
                    node* newTravel = new node(stop, currFlight->dist + dist, currFlight->stops + 1);
                    pq.push(newTravel);
                }
            }
        }
        return ans==INT_MAX ? -1 : ans;
    }
};