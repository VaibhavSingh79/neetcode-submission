class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int area = 0;
        for(int i=0; i < n; i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                int left = 0;
                int curr = st.top();
                st.pop();
                if(st.empty()) left = -1;
                else left = st.top();
                area = max(area, heights[curr] * (i-left-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int curr = st.top();
            st.pop();
            int left = st.empty() ? -1 : st.top();
            area = max(area, heights[curr] * (n-left-1));
        }
        return area;
    }
};
