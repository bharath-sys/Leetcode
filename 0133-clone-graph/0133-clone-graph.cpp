/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        queue<Node*> q;
        unordered_map<int,Node*> mp;
        Node* copy = new Node(node->val);
        mp[node->val] = copy;
        q.push(node);
        while(q.size()){
            Node* parent = q.front();
            q.pop();
            // iterate nbrs of parent and assign to clone
            for(auto nbr:parent->neighbors){
                if(mp.find(nbr->val)==mp.end()){
                    mp[nbr->val] = new Node(nbr->val);
                    q.push(nbr);
                }
                Node* parentCopy = mp[parent->val];
                Node* childCopy = mp[nbr->val];
                parentCopy->neighbors.push_back(childCopy);
            }
        }
        return copy;
    }
};