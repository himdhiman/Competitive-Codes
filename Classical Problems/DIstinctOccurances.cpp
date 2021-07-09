#include <bits/stdc++.h>
using namespace std;

int DistinctOccurances(string s, string t, int ls, int lt){
    if(lt == 0){
        return 1;
    }
    if(ls == 0){
        return 0;
    }
    if(s[ls-1] != t[lt-1]){
        return DistinctOccurances(s, t, ls-1, lt);
    }
    return DistinctOccurances(s, t, ls-1, lt-1) + DistinctOccurances(s, t, ls-1, lt);
}


int DistinctOccurancesDP(string s, string t, int ls, int lt){
    int dp[ls+1][lt+1];
    for(int i = 0; i <= ls; i++){
        for(int j = 0; j <= lt; j++){
            if(j == 0){
                dp[i][j] = 1;
            }else if(i == 0){
                dp[i][j] = 0;
            }else if(s[i-1] != t[j-1]){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        }
    }
    return dp[ls][lt];
}

int DistinctOccurancesDPEfficient(string s, string t, int ls, int lt){
    int arr[2][lt+1];
    arr[0][0] = 1;
    for(int j = 1; j <= lt; j++){
        arr[0][j] = 0;
    }
    for(int i = 1; i <= ls; i++){
        for(int j = 0; j <= lt; j++){
            if(j == 0){
                arr[1][j] = 1;
            }else if(s[i-1] != t[j-1]){
                arr[1][j] = arr[0][j];
            }else{
                arr[1][j] = arr[0][j] + arr[0][j-1];
            }
        }
        for(int j = 0; j <= lt; j++){
            arr[0][j] = arr[1][j];
        }
    }
    return arr[1][lt];
}

int main() {
    string s1 = "banana", s2 = "ban";
    cout<<DistinctOccurances(s1, s2, s1.length(), s2.length())<<endl; 
    cout<<DistinctOccurancesDP(s1, s2, s1.length(), s2.length())<<endl;
    cout<<DistinctOccurancesDPEfficient(s1, s2, s1.length(), s2.length())<<endl;
    
}
