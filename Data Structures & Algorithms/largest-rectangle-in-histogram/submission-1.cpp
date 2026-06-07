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

/*
APPROACH: Monotonic Increasing Stack
- O(n) time | O(n) space

CORE IDEA:
  For every bar, the largest rectangle it can form is bounded by
  the nearest shorter bar on its left and right.
  A bar gets processed the moment a shorter bar arrives to its right
  — that shorter bar IS its right wall.
  The new stack top after popping IS its left wall.

STEPS:
  1. Traverse heights left to right, storing indices in stack
  2. When heights[i] < heights[st.top()] → right wall found
     → pop, calculate left wall from new stack top (-1 if empty)
     → area = height * (right - left - 1), update max
  3. Push current index regardless
  4. After loop, drain remaining stack with right wall = n
     → these bars never found a shorter bar to their right

PATTERN: Monotonic increasing stack
  Stack stays increasing because the moment a shorter bar
  arrives, everything taller gets resolved and popped.
*/