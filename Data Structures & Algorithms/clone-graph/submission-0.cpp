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
        if(node == NULL) return NULL;

        unordered_map<Node*, Node*> mp;

        return dfs(node, mp);
    }


    Node* dfs(Node* node, unordered_map<Node*, Node*> &mp){
        //firstly I check if it's already checked or not
        if(mp.find(node) != mp.end()){ //it means it's already checked, so I return it???
            return mp[node];
        }
        //if it's not found in that case I create a clone
        Node* clone = new Node(node->val);

        mp[node] = clone;

        //now I traverse through my node's neighbors
        for(auto &it: node -> neighbors){
            clone -> neighbors.push_back(dfs(it, mp));
        }

        return clone;
    }
};
