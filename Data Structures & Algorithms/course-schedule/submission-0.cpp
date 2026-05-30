class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0); //the number of courses and their indegree
        vector<vector<int>> adj(numCourses); 

        for(auto &pre : prerequisites){
            indegree[pre[0]]++; // Fixed: lowercase 'd' and square brackets []
            adj[pre[1]].push_back(pre[0]); // Fixed: typo 'adj' and syntax
        }

        queue<int> q;
        //now I will check for any values that are 0
        for(int i=0; i < numCourses; i++){
            if(indegree[i] == 0){ // Fixed: lowercase 'd'
                q.push(i);
            }
        }

        int lvlBeaten = 0;
        while(!q.empty()){
            int current = q.front();
            q.pop(); //pop the level
            
            //level is beaten
            lvlBeaten++; // Fixed: removed stray 'lvl'
            
            //now I will iterate through adj and find which levels are unlocked
            for(int nextCourse : adj[current]){
                indegree[nextCourse]--;
                if(indegree[nextCourse] == 0){
                    q.push(nextCourse);
                }
            }
        }

        return numCourses == lvlBeaten;
    }
};