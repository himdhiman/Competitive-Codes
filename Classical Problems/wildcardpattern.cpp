#include <bits/stdc++.h>
using namespace std;

bool WildCardMatching(string s1, string s2, int l1, int l2, int i, int j){
    if(i == l1 && j == l2){
        return true;
    }

    if(s2[j] == '*' && j+1 != l2 && l1 == i){
        return false;
    } 

    if(s2[j] == '?' || s1[i] == s2[j]){
        return WildCardMatching(s1, s2, l1, l2, i+1, j+1);
    }
    if(s2[j] == '*'){
        return WildCardMatching(s1, s2, l1, l2, i+1, j) || WildCardMatching(s1, s2, l1, l2, i, j+1);
    }
    return false;
}



bool WildCardMatchingMemoization(string s1, string s2, int l1, int l2, int i, int j, int arr[][100]){
    if(i == l1 && j == l2){
        return true;
    }
    if(s2[j] == '*' && j+1 != l2 && i == l1){
        return false;
    }
    if(arr[i][j] != -1){
        return arr[i][j];
    }
    if(s2[j] == '?' || s1[i] == s2[j]){
        return WildCardMatchingMemoization(s1, s2, l1, l2, i+1, j+1, arr);
    }
    if(s2[j] == '*'){
        return arr[i][j] = WildCardMatchingMemoization(s1, s2, l1, l2, i+1, j, arr) || WildCardMatchingMemoization(s1, s2, l1, l2, i, j+1, arr);
    }
    return false;
}


int main() {
    string s1 = "baaabab";
    string s2 = "*****ba*****ab";
    cout<<WildCardMatching(s1, s2, s1.length(), s2.length(), 0, 0)<<endl;
    int arr[100][100];
    memset(arr, -1, sizeof(arr));
    cout<<WildCardMatchingMemoization(s1, s2, s1.length(), s2.length(), 0, 0, arr);
}
