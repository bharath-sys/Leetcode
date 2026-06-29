class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size()==0)return true;
        queue<int> q;
        vector<int> indeg(numCourses, 0);
        vector<vector<int>> adj(numCourses,vector<int>());
        for (auto req : prerequisites) {
            indeg[req[0]]++;
            adj[req[1]].push_back(req[0]);
        }
        for (int i=0;i<numCourses;i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        if(!q.size())return false;
        int processed = 0;
        while(q.size()){
            int parent = q.front();
            q.pop();
            processed+=1;
            for(int nbr:adj[parent]){
                indeg[nbr]-=1;
                if(indeg[nbr]==0)q.push(nbr);
            }
        }
        return processed==numCourses;
    }
};