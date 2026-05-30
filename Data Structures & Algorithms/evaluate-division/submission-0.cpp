class Solution {
public:
    double dfs(string src, string dst, unordered_set<string> &visited, unordered_map<string, vector<pair<string, double>>> &adj){
        if(adj.find(src) == adj.end() || adj.find(dst) == adj.end()){ //it doesn't exist
            return -1.0;
        }
        //it exists in visited 
        if(visited.find(src) != visited.end()){ 
            return -1.0;
        }
        //for cases like a*a or b*b
        if(src == dst){
            return 1.0;
        }
        //after all checks I mark it as visited
        visited.insert(src);

        //deep dive in dfs
        for(auto &it : adj[src]){
            string node = it.first;
            double wt = it.second;

            double result = dfs(node, dst, visited, adj);
            if(result != -1.0){
                return result * wt;
            }

        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        unordered_map<string, vector<pair<string, double>>> adj;
        //fill it ?
        for(int i=0; i < equations.size(); i++){
            string u = equations[i][0];
            string v = equations[i][1];

            double val = values[i];

            adj[u].push_back({v, val}); //this is my u/v
            adj[v].push_back({u, 1.0/val}); //this my v/u
        }

        //till upper portion I created a adj map
        //now I will have to see how to process queries bcz my dfs will run on queries
        vector<double> results;
        for(auto &query : queries){
            unordered_set<string> visited;
            string src = query[0];
            string dst = query[1];

            results.push_back(dfs(src, dst, visited, adj));
        }

        return results;


    }
};