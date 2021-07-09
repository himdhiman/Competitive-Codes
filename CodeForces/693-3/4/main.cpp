#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 200005;
int arr[N];

void solve(){
	int n;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	sort(arr, arr+n);
	int a = 0, b = 0;
	int turn = 1;
	for(int i = n-1; i >= 0; i--){
		if(turn){
			if(!(arr[i]&1)){
				a += arr[i];
			}
		}else{
			if(arr[i]&1){
				b += arr[i];
			}
		}
		turn = !turn;
	}
	if(a > b){
		cout<<"Alice"<<endl;
		return;
	}
	if(b > a){
		cout<<"Bob"<<endl;
		return;
	}
	cout<<"Tie"<<endl;


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