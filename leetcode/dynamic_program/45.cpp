#include<iostream>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
        }

        if(sum % 2 != 0) return false;
        int target = sum /2 ;

        vector<int> dp(target + 1, 0);
        for(int i = 0; i < nums.size(); ++i){
            for(int j = target; j >= nums[i]; --j){
                dp[j] = max(dp[j], dp[j - nums[i]] +nums[i]);
            }
        }

        if(target == dp[target]) return true;
        return false;

    }
};
int main(){


return 0;
}
