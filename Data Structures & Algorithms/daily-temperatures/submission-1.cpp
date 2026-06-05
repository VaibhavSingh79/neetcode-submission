class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        if(n==1) return {0};
        stack<int> st;
        vector<int> ans(n, 0);

        st.push(0);

        for(int i=0; i < n; i++){
            while(!st.empty() && temperatures[st.top()] < temperatures[i]){ //warmer temps exist
                int curr = st.top();
                st.pop();
                ans[curr] = i - curr;
            }
            st.push(i);
        }
        return ans;
    }
    
};
