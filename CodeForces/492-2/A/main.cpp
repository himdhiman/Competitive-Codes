#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

int arr[5] = {1, 5, 10, 20, 100};

// const int N = 10000

int solve(int n, int sum){
	if(sum == 0){
		return 0;
	}
	if(sum < 0 or n <= 0){
		return INT_MAX;
	}
	return min(solve(n-1, sum), 1 + solve(n, sum-arr[n-1]));
}

int solve2(int n, int sum){
	int ans = 0;
	while(sum != 0){
		if(arr[n] <= sum){
			sum = sum-arr[n];
			ans++;
		}else{
			n--;
		}
	}
	return ans;
}


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int n;
	cin>>n;
	cout<<solve2(4, n);


	return 0;
}