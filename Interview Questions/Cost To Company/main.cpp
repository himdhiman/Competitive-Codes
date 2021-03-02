#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

void solve(int i, int n, int hire, int sal, int sev, int* ans){
	if(i == n){
		return;
	}
	int emps = arr[i];
	if(emps < arr[i-1]){
		int temp = INT_MIN;
		while(emps < arr[i-1]){
			temp = max()
		}
	}
	
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int n;
	cin>>n;
	for(int i = 0; i < n; cin>>arr[i++]);
	int hire, int sal, int sav;
	cin>>hire>>sal>>sav;
	int ans = arr[0]*(hire+sal);

	


	return 0;
}