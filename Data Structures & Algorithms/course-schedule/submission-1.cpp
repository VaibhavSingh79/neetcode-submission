class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0); //a array of size courses filled with 0s
        vector<vector<int>> final(numCourses);
        int lvl = 0;

        //now iterate in array and update every course's count
        for(auto &pre : prerequisites){
            inDegree[pre[0]]++; //increment the count of every level
            //can I do the second iteration for updating my final array here ??????
            //if I take the same elements I am using and address them by their index, I can
            final[pre[1]].push_back(pre[0]);
            //this way I update my adj array
        }

        //if there is any with inDegree 0 I will push it to my queue
        queue<int> q;

        for(int i=0; i < numCourses; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        //now my array is ready , let's start iterating 
        while(!q.empty()){
            int current = q.front(); //the place where I am sitting currently
            q.pop();
            lvl++;
            //now one level is done let's check for others that are done also
            for(int nxt : final[current]){
                inDegree[nxt]-- ;
                if(inDegree[nxt] == 0){
                    q.push(nxt);
                }
            }
        }
        return lvl == numCourses;
    }
};