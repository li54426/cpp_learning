#include<iostream>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        if(len == 1) return nums[0];
        if(len == 2) return max(nums[0], nums[1]);
        return max(do_rob(nums, 0, len-2), do_rob(nums, 1, len-1));
    }//rob

    int do_rob(vector<int> &nums, int left, int right){
        //the fuction coverde left and right;
        //the min len is 3

        int len = nums.size();
        vector<int> dp(len + 1, 0);

        dp[left] = nums[left];
        dp[left + 1] = max(nums[left], nums[left + 1]);

        for(int i = left + 2; i <= right; ++i){
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }

        return dp[right];

    }//do_rob

};

int main(){

return 0;
}


