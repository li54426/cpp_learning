#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //dp[amount] = sum dp[amount - coin]
        vector<int> dp(amount +1 , 0);
        dp[0] =1;
        for(int coin : coins)
        {
            for(int curamount = 1 ; curamount <= amount ; ++curamount)
            {
                int leftamount = curamount - coin;
                if(leftamount < 0 || dp[leftamount] ==0)
                    continue;

                dp[curamount] += dp[leftamount];

            }
        }
        for(int d : dp)
            cout << d <<endl;
        return dp[amount];

    }
};

int main(){


    vector<int> v= {1,2,5};

    Solution s ;
    cout << s.change(5, v);
return 0;
}
