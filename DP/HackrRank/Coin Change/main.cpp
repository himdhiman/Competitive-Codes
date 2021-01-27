#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

// const int N = 100005;
int arr[251][51];

int solve(int n, vector<int> c, int i){
    if(n == 0){
        return 1;
    }
    if(i == 0){
        return 0;
    }
    if(arr[n][i] != -1){
        return arr[n][i];
    }
    if(c[i-1] > n){
        return arr[n][i] = solve(n, c, i-1);
    }
    return arr[n][i] = solve(n-c[i-1], c, i) + solve(n, c, i-1);
 }



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	memset(arr, -1, sizeof arr);
	int n, t;
	cin>>n>>t;
	vector<int> c(t, 0);
	for(int i = 0; i < t; i++){
		cin>>c[i];
	}
	int i = c.size();
	cout<<solve(n, c, i);
	


	return 0;
}