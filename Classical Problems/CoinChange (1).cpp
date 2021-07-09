#include <bits/stdc++.h>
using namespace std;

int MinCoins(int coins[], int numberOfCoins, int val){
    if(val == 0){
        return 0;
    }
    if(numberOfCoins == 0 || val < 0){
        return 100000;
    }
    return min(1 + MinCoins(coins, numberOfCoins, val-coins[numberOfCoins-1]), MinCoins(coins, numberOfCoins-1, val));   
}


int MinCoinsDP(int coins[], int numberOfCoins, int val){
    int dp[numberOfCoins+1][val+1];
    for(int i = 0; i <= numberOfCoins; i++){
        for(int j = 0; j <= val; j++){
            if(j == 0){
                dp[i][j] = 0;
            }
            if(i == 0){
                dp[i][j] = 100000000;
            }
        }
    }
    for(int i = 1; i <= numberOfCoins; i++){
        for(int j = 1; j <= val; j++){
            if(j-coins[i-1] < 0){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = min(1 + dp[i][j-coins[i-1]], dp[i-1][j]);
            }
        }
    }
    for(int i = 0; i <= numberOfCoins; i++){
        for(int j = 0; j <= val; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[numberOfCoins][val];
}

int main() {
    int coins[4] = {2, 5, 3, 6};
    int ans = MinCoinsDP(coins, 4, 10);
    if(ans == 100000000){
        cout<<"NOT POSSIBLE";
    }else{
        cout<<ans;
    }
}
