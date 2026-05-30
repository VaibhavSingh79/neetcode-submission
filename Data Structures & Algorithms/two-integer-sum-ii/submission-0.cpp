class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        int end = numbers.size()-1;

        while(start < end){ 
            int curr_sum = numbers[start] + numbers[end];
            if(curr_sum > target){
                end--;
            }
            else if(curr_sum == target){
                break;
            }
            else{
                start++;
            }
        }
        return {start+1, end+1};
    }
};
