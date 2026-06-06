class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        stack<int> st;
        unordered_map<int, int> mp;
        vector<int> ans(n, -1);

        //fill the map
        for(int i=0; i < n; i++){
            mp[nums1[i]] = i;
        }

        for(int i=0; i < m; i++){
            while(!st.empty() && st.top() < nums2[i]){
                int curr = st.top();
                st.pop();
                if(mp.count(curr) > 0){ //it exists in map?
                    ans[mp[curr]] = nums2[i];
                }
            }
            st.push(nums2[i]);
        }
        return ans;
    }
};

//my approach
/*
KEY INSIGHT:
  nums2 is the universe. nums1 is just a list of queries.
  "next greater" is always defined within nums2, not nums1.

STEPS:
  1. Build map: value → index in ans, for every element in nums1
  2. Traverse nums2 left to right
  3. Stack holds "waiting" elements (haven't found next greater yet)
  4. When nums2[i] > stack top → nums2[i] IS the answer for top
     → pop, check map, record ans[map[popped]] = nums2[i]
  5. Push nums2[i] regardless (it's now waiting for its own answer)
  6. Anything left in stack at the end → no greater element → stays -1

PATTERN: Monotonic decreasing stack
  Stack always stays in decreasing order because anything
  smaller gets resolved and popped immediately.
*/