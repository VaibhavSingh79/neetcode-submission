class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int total = m+n;
        int k = total/2; //the number of elements I'll need
        double ans = 0.0;
        if(checker(nums1, nums2, k, total,ans)){
            return ans;
            
        }
        else{
            checker(nums2, nums1,k, total, ans);
            return ans;
        }

    }
    bool checker(vector<int> &nums1, vector<int> &nums2, int k, int total ,double &ans){
        int start = 0;
        int end = nums1.size()-1;
        while(start <= end){
            int mid = start + (end-start)/2; //the elements I will pick from first array
            int j = k-mid; //the elements I will pick from second array
            
            //now there are cases for j
            if(j < 0){ //it means my mid is very big
                end = mid-1; //we need to go back
                continue;
            }
            if(j > nums2.size()){ //it means my mid is too small, need to move fwd
                start = mid+1;
                continue;
            }

            bool is_greater_than_left = (j == nums2.size()) || nums1[mid] <= nums2[j];
            bool is_greater_than_right = (j == 0) || nums1[mid] >= nums2[j-1];

            if(is_greater_than_left && is_greater_than_right){ //ans is found
                if(total%2 != 0){
                    ans = nums1[mid]; //in odd elements my mid is ans obv
                }
                //let's say my ans is even, in that case I'm gonna need sums of both
                else{
                    int nums1_left = (mid==0) ? INT_MIN : nums1[mid-1];
                    int nums2_left = (j == 0) ? INT_MIN : nums2[j-1];

                    int left_max = max(nums1_left, nums2_left);

                    ans = (nums1[mid] + left_max)/2.0;
                }
                return true;
            } 

            //now two cases, one edge found other not
            if(is_greater_than_left){
                //means ain't bigger than right element
                start = mid+1;
            }
            else{
                //means is bigger than right
                end = mid-1;
            }
        }
        return false;
    }
};
