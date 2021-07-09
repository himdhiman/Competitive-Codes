#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

void solve(){
	int n, d;
	cin>>n>>d;
	if(d == 1){
		int val
		for(int i = 0; i < d; i++){
			cin>>val;
			cout<<"YES"<<" ";
		}
		cout<<endl;
		return;
	}

	if(d == 2){
		int val;
		for(int i = 0; i < d; i++){
			cin>>val;
			if(val&1){
				cout<<"NO"<<" ";
			}else{
				cout<<"YES"<<" ";
			}
		}
		cout<<endl;
		return;
	}

	if(d == 3){
		int val;
		cin>>val;
		for(int i = 0; i < n; i++){
			
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