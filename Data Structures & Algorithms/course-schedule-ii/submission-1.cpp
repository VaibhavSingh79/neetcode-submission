class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> final(numCourses);
        int lvl = 0; //counter

        for(auto &pre : prerequisites){
            inDegree[pre[0]]++;
            final[pre[1]].push_back(pre[0]); //to be able to do course 'a' what all courses will I have to do ?
        }
        queue<int> q;
        vector<int> outputt;
        for(int i=0; i < numCourses; i++){
            if(inDegree[i] == 0){
                q.push(i); //this course has no pre left we can proceed with this one
                outputt.push_back(i); //because this is the first ever course I found, this is not recursion that I'll come back
            }
        }

        //both arrays -  check
        // inDegree - check

        while(!q.empty()){ //while my queue is not empty let's start putting up elements
            int current = q.front(); //I store the front of my queue
            q.pop(); //this level is done, and bcz I placed the my logic while pushing popping m push makes no sense
            lvl++ ;
            for(int nxt : final[current]){ //specific course m jaake I'm checking what all prerequisites it has 
                inDegree[nxt]-- ; //this is the level whose inDegree is less now
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
