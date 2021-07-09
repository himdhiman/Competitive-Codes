#include <bits/stdc++.h>
using namespace std;

void CoinChange(vector<int> coins, int val, int j, vector<int> &output, vector<vector<int> > &result){
    if(val == 0){
        result.push_back(output);
        return;
    }
    if(val < 0){
        return;
    }
    for(int i = j; i < coins.size(); i++){
        output.push_back(coins[i]);
        CoinChange(coins, val-coins[i], i, output, result);
        output.pop_back();
    }
    return;
}

int CoinChange2(vector<int> coins, int val, int n){
    if(val == 0){
        return 1;
    }
    if(val < 0 || n < 0){
        return 0;
    }
    // include + exclude
    return CoinChange2(coins, val-coins[n], n) + CoinChange2(coins, val, n-1);
}

int DP[100] = {0};

int CoinChangeDP(vector<int> coins, int val, int n){
    if(val == 0){
        return 1;
    }
    if(val < 0 || n < 0){
        return 0;
    }
    if(DP[val] != 0){
        return DP[val];
    }
    // include + exclude
    return DP[val] = CoinChangeDP(coins, val-coins[n], n) + CoinChangeDP(coins, val, n-1);
}

int CoinChangeBottomUp(vector<int> coins, int val){
    vector<int> dp;
    dp.resize(val+1);
    for(int i = 0; i < dp.size(); i++){
        dp[i] = 0;
    }
    dp[0] = 1;
    for(int i = 0; i < coins.size(); i++){
        for(int j = coins[i]; j <= val; j++){
            dp[j] += dp[j - coins[i]];
        }
    }
    return dp[val];
}


int main() {
    vector<int> coins = {2, 5, 3, 6};
    int val = 10;
    vector<int> output;
    vector<vector<int> > result;
    CoinChange(coins, val, 0, output, result);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Total Combinations : "<<CoinChange2(coins, val, coins.size()-1)<<endl;
    cout<<"Total Combinations : "<<CoinChangeDP(coins, val, coins.size()-1)<<endl;
    cout<<"Total Combinations : "<<CoinChangeBottomUp(coins, val)<<endl;
    return 0;
}
