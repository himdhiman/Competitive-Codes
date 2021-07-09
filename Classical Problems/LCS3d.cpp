#include <bits/stdc++.h>
using namespace std;

int LCS3D(string s1, string s2, string s3, int l1, int l2, int l3){
    if(l1 < 0 || l2 < 0 || l3 < 0){
        return 0;
    }
    if(s1[l1] == s2[l2] && s2[l2] == s3[l3]){
        return 1 + LCS3D(s1, s2, s3, l1-1, l2-1, l3-1);
    }
    return max(LCS3D(s1, s2, s3, l1, l2, l3-1), max(LCS3D(s1, s2, s3, l1, l2-1, l3), LCS3D(s1, s2, s3, l1-1, l2, l3)));
}

int LCSdp(string s1, string s2, string s3, int l1, int l2, int l3){

    int dp[l1+1][l2+1][l3+1];
    for(int i = 0; i <= l1; i++){
        for(int j = 0; j <= l2; j++){
            for(int k = 0; k <= l3; k++){
                if(i == 0 || j == 0 || k == 0){
                    dp[i][j][k] = 0;
                }else if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1]){
                    dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
                }else{
                    dp[i][j][k] = max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1]));
                }
            }
        }
    }
    return dp[l1][l2][l3];
}

int main() {
    string s1, s2, s3;
    s1 = "abcd1e2";
    s2 = "bc12ea";
    s3 = "bd1ea";
    cout<<LCSdp(s1, s2, s3, s1.length(), s2.length(), s3.length());
}
