#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100;
int arr[N];
int dp1[N];
int dp2[N];




int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int n, q, s;
	cin>>n>>q>>s;
	for(int i = 1; i <= n; i++){
		cin>>arr[i];
	}
	for(int i = 1; i <= n; i++){
		dp2[i] = 1;
		dp1[i] = 1;
	}
	int maximum = 1;
	for(int i = 2; i <= n; i++){
		for(int j = 1; j < i; j++){
			if(arr[i] > arr[j]){
				dp1[i] = max(dp1[i], dp1[j]+1);
			}
			maximum = max(maximum, dp1[i]);
			dp2[i] = maximum;
		}
	}
	for(int i = 1; i <= n; i++){
		cout<<dp2[i]<<" ";
	}
	cout<<endl;
	int last = 0;
	for(int i = 0; i < q; i++){
		int x, y;
		cin>>x>>y;
		int l = (x+s*last-1)%n+1;
		int r = (y+s*last-1)%n+1;
		if(l > r){
			swap(l, r);
		}
		int last;
		if(l == 1){
			last = dp2[r];
		}else{
			last = dp2[r]-dp2[l]+1;
		}
		cout<<r<<" "<<l<<endl;
		cout<<last<<endl;
	}


	


	return 0;
}