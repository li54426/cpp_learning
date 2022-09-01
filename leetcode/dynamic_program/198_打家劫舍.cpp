#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        int len = nums.size();
        vector<int> dp(nums.size());

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i =2; i < len  ;i++){
            dp[i] = max(dp[i-1] , dp[i-2] + nums[i]);
        }
        return dp[len-1];


    }
};

int main(){
    vector<int> nums = {1,2,3,1};
    Solution s;
    cout << s.rob(nums);

return 0;
}
