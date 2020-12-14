#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 101;
int arr[N][N];
int n, m, k;

int solve(int i, int j){
	if(i == n-1 and j == n-1){
		return arr[n-1][m-1];
	}
	if(i == n-1){
		
	}
	if(arr[i][j] < k){

	}
}


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin>>arr[i][j];
			}
		}
		if(arr[0][0] > k){
			cout<<-1<<endl;
		}else{
			cout<<arr[0][0] + solve(0, 0);
		}
	}
	


	return 0;
}