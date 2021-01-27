#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 1005;
int arr[N][N];
int r, c;
int fibo[N];

bool isValid(int i, int j){
	if(i >= 0 and i < r and j >= 0 and j < c){
		return true;
	}
	return false;
}

int fib(int n){
	if(n == 0 || n == 1){
		return n;
	}
	if(fibo[n] != -1){
		return fibo[n];
	}
	return fibo[n] = fib(n-1) + fib(n-2);
}

int solve(int i, int j){
	if(i == r){
		return 0;
	}
	int ans1 = INT_MIN, ans2 = INT_MIN;
	int a = __gcd(fib(i+1), fib(j+1));
	if(a%2){
		if(isValid(i+1, j+1)){
			ans1 = arr[i][j] + solve(i+1, j+1);
		}
		if(isValid(i+1, j-1)){
			ans2 = arr[i][j] + solve(i+1, j-1);
		}
	}else{
		if(isValid(i+1, j+1)){
			ans1 = solve(i+1, j+1);
		}
		if(isValid(i+1, j-1)){
			ans2 = solve(i+1, j-1);
		}	
	}

	return max(ans1, ans2);
	
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin>>r>>c;
	memset(fibo, -1, sizeof fibo);
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cin>>arr[i][j];
		}
	} 
	int ans = INT_MIN;
	for(int i = 0; i < c; i++){
		ans = max(ans, solve(0, i));
	}
	cout<<ans;


	return 0;
}