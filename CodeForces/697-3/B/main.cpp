#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 1000005;
int arr[N] = {0};

void solve(){
	int n;
	cin>>n;
	if(arr[n]){
		cout<<"YES"<<endl;
		return;
	}
	cout<<"NO"<<endl;


	return;
}



int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	for(int i = 0; i <= 10000; i++){
		for(int j = 0; j <= 10000; j++){
			int temp = 2021*i + 2020*j;
			if(temp < N){
				arr[temp] = 1;
			}
		}
	}

	int t;
	// t = 1;
	cin>>t;
	while(t--) solve();

	


	return 0;
}