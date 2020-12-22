#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];
int newArr[N];

void solve(int n, int k){

	k = k % n;

	int ind = 0;
	for(int i = n-k; i < n; i++){
		newArr[ind++] = arr[i]; 
	}
	for(int i = 0; i < n-k; i++){
		newArr[ind++] = arr[i];
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
		int n, k;
		cin>>n>>k;
		// cout<<n<<k;
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}
		solve(n, k);
		for(int i = 0; i < n; i++){
			cout<<newArr[i]<<" ";
		}
		cout<<endl;
	}
	


	return 0;
}