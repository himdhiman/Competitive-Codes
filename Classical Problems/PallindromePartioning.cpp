#include <bits/stdc++.h>
using namespace std;

bool isPallindrome(string s, int i, int j){
    while(i <= j){
        if(s[i++] != s[j--]){
            return false;
        }
    }
    return true;
}

int PallindromePartioning(string s, int i, int j, int dp[][20]){
    if(i >= j){
        return 0;
    }
    if(isPallindrome(s, i, j)){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int minimum = INT_MAX;
    for(int k = i; k < j; k++){
        int temp = PallindromePartioning(s, i, k, dp) + PallindromePartioning(s, k+1, j, dp) + 1;
        minimum = min(minimum, temp);
    }
    return dp[i][j] =  minimum;
}

int main() {
    string s = "abcd";
    int dp[20][20];
    memset(dp, -1, sizeof(dp));
    cout<<PallindromePartioning(s, 0, s.length()-1, dp);
}
