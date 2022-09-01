#include<iostream>
#include<vector>

using namespace std;

    class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len , 10000);
        dp[len-1] = 0;

        for(int i = len - 2; i > -1; --i){
            int end = min(i + nums[i], len-1);
            for(int j = i+1 ; j <= end; ++j){
                dp[i] = min(dp[i] , dp[j]+1);
            }

        }
    return dp[0];
    }
};
int main(){


    vector<int> v= {2,3,1,1,4};

    Solution s ;
    cout << s.jump(v);
return 0;
}
