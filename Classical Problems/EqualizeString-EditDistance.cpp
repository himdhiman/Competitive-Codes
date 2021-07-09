#include <bits/stdc++.h>
using namespace std;

int EditDistance(string s1, string s2, int l1, int l2){
    if(l1 == 0){
        return l2;
    }
    if(l2 == 0){
        return l1;
    }
    if(s1[l1-1] == s2[l2-1]){
        return EditDistance(s1, s2, l1-1, l2-1);
    }
    return 1 + min(EditDistance(s1, s2, l1, l2-1), min(EditDistance(s1, s2, l1-1, l2), EditDistance(s1, s2, l1-1, l2-1)));
}

int EditDistanceTopDown(string s1, string s2, int l1, int l2, int TopDown[][1000]){
    if(l1 == 0){
        return l2;
    }
    if(l2 == 0){
        return l1;
    }
    if(TopDown[l1][l2] != -1){
        return TopDown[l1][l2];
    }
    if(s1[l1-1] == s2[l2-1]){
        return EditDistanceTopDown(s1, s2, l1-1, l2-1, TopDown);
    }
    return TopDown[l1][l2] =  1 + min(EditDistanceTopDown(s1, s2, l1, l2-1, TopDown), min(EditDistanceTopDown(s1, s2, l1-1, l2, TopDown), EditDistanceTopDown(s1, s2, l1-1, l2-1, TopDown)));
}

int EditDistanceDP(string s1, string s2, int l1, int l2){
    int dp[l1+1][l2+1];
    for(int i = 0; i <= l1; i++){
        for(int j = 0; j <= l2; j++){
            if(i == 0){
                dp[i][j] = j;
            }else if(j == 0){
                dp[i][j] = i;
            }else if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            }
        }
    }
    return dp[l1][l2];
}

int EditDistanceOptimized(string s1, string s2, int l1, int l2){
    int arr[2][l2+1];
    for(int i = 0; i <= l2; i++){
        arr[0][i] = i;
    }
    for(int i = 1; i <= l1; i++){
        for(int j = 0; j <= l2; j++){
            if(j == 0){
                arr[1][j] = i;
            }else if(s1[i-1] == s2[j-1]){
                arr[1][j] = arr[0][j-1];
            }else{
                arr[1][j] = 1 + min(min(arr[0][j], arr[1][j-1]), arr[0][j-1]);
            }
        }
        for(int k = 0; k <= l2; k++){
            arr[0][k] = arr[1][k];
        }
    }
    return arr[1][l2];
}


int main() {
    string s1 = "abcde";
    string s2 = "bcdae";
    cout<<EditDistance(s1, s2, s1.length(), s2.length())<<endl;
    int TopDown[1000][1000];
    memset(TopDown, -1, sizeof(TopDown));
    cout<<EditDistanceTopDown(s1, s2, s1.length(), s2.length(), TopDown)<<endl;
    cout<<EditDistanceDP(s1, s2, s1.length(), s2.length())<<endl;
    cout<<EditDistanceOptimized(s1, s2, s1.length(), s2.length())<<endl;
    return 0;
}
