#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 300005;
int arr[N];

void solve(){
	int n;
	cin>>n;
	int mx = INT_MIN;
	for(int i = 0; i <n; i++){
		cin>>arr[i];
		mx = max(mx, arr[i]);
	}
	bool flag = true;
	for(int i = 1; i < n; i++){
		if(arr[i-1] != arr[i]){
			flag = false;
			break;
		}
	}
	if(flag){
		cout<<-1<<endl;
		return;
	}
	for(int i = 0; i < n; i++){
		if(arr[i] == mx){
			if(i == 0){
				if(arr[i+1] != arr[i]){
					cout<<i+1<<endl;
					return;
				}
			}else if(i == n-1){
				if(arr[i] != arr[i-1]){
					cout<<i+1<<endl;
					return;
				}
			}else{
				if(arr[i] != arr[i+1]){
					cout<<i+1<<endl;
					return;
				}
				if(arr[i] != arr[i-1]){
					cout<<i+1<<endl;
					return;
				}
			}
		}
	}

	return;
}



int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	// t = 1;
	cin>>t;
	while(t--) solve();

	


	return 0;
}