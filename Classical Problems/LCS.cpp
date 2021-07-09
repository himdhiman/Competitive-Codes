#include <bits/stdc++.h>
using namespace std;

int DP[100][100] = {0};

int LCS(string s1, string s2, int l1, int l2){
    if(l1 < 0 || l2 < 0){
        return 0;
    }
    if(DP[l1][l2] != 0){
        return DP[l1][l2];
    }
    if(s1[l1] == s2[l2]){
        return 1 + LCS(s1, s2, l1-1, l2-1);
    }
    return DP[l1][l2] = max(LCS(s1, s2, l1, l2-1), LCS(s1, s2, l1-1, l2));
}


int LCSBottomUp(string s1, string s2, int l1, int l2){
    int arr[l1+1][l2+1];
    
    for(int i = 0; i <= l1; i++){
        for(int j = 0; j <= l2; j++){
            if(i == 0 || j == 0){
                arr[i][j] = 0;
            }
            else if(s1[i-1] == s2[j-1]){
                arr[i][j] = 1 + arr[i-1][j-1];
            }else{
                arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
            }
        }
    }
    for(int i = 0; i <= l1; i++){
        for(int j = 0; j <= l2; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    return arr[l1][l2]; 
}



int main() {
    string s1 = "abc";
    string s2 = "acd";
    cout<<LCSBottomUp(s1, s2, s1.length(), s2.length());
    return 0;
}
