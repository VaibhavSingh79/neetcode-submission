class Solution {
public:
    vector<int> memo;
    int calci(string &s, int index){
        //write all base cases
        //first if reach the end
        if(index == s.size()){
            return 1;
        }

        //if the index is 0, i cannot do anything
        if(s[index] == '0'){
            return 0;
        }
        if(memo[index] != -1) return memo[index];
        int one = calci(s, index+1);
        int two = 0;
        if(index+1 < s.size() && stoi(s.substr(index,2)) <= 26){
            two = calci(s, index+2);
        }

        return memo[index] = one + two;


    }
    int numDecodings(string s) {
        int n = s.size();
        memo.assign(n, -1);
        return calci(s, 0);
    }
};
