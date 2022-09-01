#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int M = dungeon.size();
        int N = dungeon[0].size();
        //0或者负数就死了;  只能向右边, 或者向下,看谁征得更小, 也就是负数最大
        //不仅考虑前一个状态, 还要考虑以前的状态
        vector<vector<int> > dp(M, vector<int>(N, 0));
        dp[M-1][N-1] = dungeon[M-1][N-1]>0 ? 1 : 1-dungeon[M-1][N-1];
        int res = 0;
        for(int i=N-2; i>-1; --i){
            res = dp[M-1][i+1] - dungeon[M-1][i];
            dp[M-1][i] = res <0 ? 1 : res;
        }
        for(int i = N-2; i>-1; --i){
            res = dp[i+1][N-1] -dungeon[i][N-1];
            dp[i][N-1] = res  <0 ? 1: res;
        }


        for(int i =M-2; i>=0; --i){
            for(int j =N-2; j>=0; --j){
                res = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
                dp[i][j] = res<0 ? 1 : res;
                //cout <<dp[i][j]<<'\t';
            }
            //cout<<endl;
        }
        for(int i = 0; i < M; ++i){
            for(int j = 0; j<N ; ++j){
                cout << dp[i][j] << "\t" ;
            }
            cout<< endl;
        }

        return dp[0][0] ;

    }
};

int main(){
    vector <vector<int> > dungeon;
    vector<int> a({0,0});
    //cout << a[0] ;
    dungeon.push_back(a);

            int M = dungeon.size();
        int N = dungeon[0].size();
        //0或者负数就死了;  只能向右边, 或者向下,看谁征得更小, 也就是负数最大
        //不仅考虑前一个状态, 还要考虑以前的状态
        vector<vector<int> > dp(M, vector<int>(N, 0));
        dp[M-1][N-1] = dungeon[M-1][N-1]>0 ? 1 : 1-dungeon[M-1][N-1];
        int res = 0;
        for(int i=N-2; i>-1; --i){
            res = dp[M-1][i+1] - dungeon[M-1][i];
            dp[M-1][i] = res <0 ? 1 : res;
        }
        for(int i = N-2; i>-1; --i){
            res = dp[i+1][N-1] -dungeon[i][N-1];
            dp[i][N-1] = res  <0 ? 1: res;
        }
        cout<<"debug"<<endl;


        for(int i =M-2; i>=0; --i){
            for(int j =N-2; j>=0; --j){
                res = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
                dp[i][j] = res<0 ? 1 : res;
                //cout <<dp[i][j]<<'\t';
            }
            //cout<<endl;
        }
        for(int i = 0; i < M; ++i){
            for(int j = 0; j<N ; ++j){
                cout << dp[i][j] << "\t" ;
            }
            cout<< endl;
        }
    cout <<"the result is " <<dp[0][0];

return 0;
}
