class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low < high){
            int mid = low + (high-low)/2;
            long long sum = 0;
            //this gets me the sum everytime 
            for(int i=0; i < piles.size(); i++){
                sum += (piles[i]+mid-1)/mid;
                if(sum > h) break;
            }
            if(sum > h){
                low = mid+1;
            }
            if(sum <= h){
                high = mid;
            }
        }
        return low;
    }
};
