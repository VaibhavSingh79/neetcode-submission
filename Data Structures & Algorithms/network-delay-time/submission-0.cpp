class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int, int>>> adj(n+1); //my adj vector 
        for(auto &ad: times){
            int u = ad[0];
            int v = ad[1];
            int w = ad[2];
            adj[u].push_back({v,w});
        }

        //pq for storing distances
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;


        vector<int> dist(n+1, 1e9); //distance array for node to node distance

        dist[k] = 0; //distance at source is supposed to be 0

        pq.push({0,k});

        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second; //at first it points to my source

            pq.pop();

            //this is optimisation, saves time and memory
            if (dis > dist[node]) continue;

            for(auto &it: adj[node]){
                int adjNode = it.first;
                int edgewt = it.second;

                if(dis + edgewt < dist[adjNode]){
                    dist[adjNode] = dis + edgewt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        int maxtime = 0;
        for(int i=1; i <= n; i++){
            if(dist[i] == 1e9) return -1;
            maxtime = max(maxtime, dist[i]);
        }
        return maxtime;
    }
};
