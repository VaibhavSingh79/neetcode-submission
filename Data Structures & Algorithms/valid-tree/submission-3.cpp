class DSU{
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n){
        parent.resize(n);
        rank.assign(n,0);
        for(int i=0; i < n; i++){
            parent[i]=i; //everybody is a parent of their own
        }
    }

    int find(int x){
        if(parent[x] != x){ //it means this is not a chief 
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    bool unite(int a, int b){
        int ra = find(a), rb = find(b);
        if(ra==rb) return false;
        if(rank[ra] > rank[rb]) parent[rb] = ra;
        else if(rank[ra] < rank[rb]) parent[ra] = rb;
        else{
            //assign any to any
            parent[rb] = ra;
            rank[ra]++;
        }
        return true;
    }
};
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        if(edges.size() != n-1) return false; //because a tree of n nodes has n-1 edges alwaysss

        for(auto & ele: edges){
            if(!dsu.unite(ele[0], ele[1])) return false; //it means there's a cycle detected so tree is not a possibility
        }
        return true;
    }
};