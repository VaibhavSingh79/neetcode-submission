class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0); //inDegree array
        vector<vector<int>> final(numCourses);
        vector<int> outputt;
        for(auto pre : prerequisites){
            inDegree[pre[0]]++ ;
            final[pre[1]].push_back(pre[0]); //to do course b I've to do a
        }

        queue<int> q;
        int lvl=0;

        for(int i=0; i < numCourses; i++){
            if(inDegree[i] == 0){
                q.push(i); //this lvl has 0 prerequisites left and can be popped soon now
                outputt.push_back(i);
            }
        }

        while(!q.empty()){
            int current = q.front();
            q.pop();
            lvl++;
            for(int nxt : final[current]){
                inDegree[nxt]-- ;
                if(inDegree[nxt] == 0){
                    q.push(nxt);
                    outputt.push_back(nxt);
                }
            }
        }

        if(lvl != numCourses) return {};
        return outputt;

    }
};
