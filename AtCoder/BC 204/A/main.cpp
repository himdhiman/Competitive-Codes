#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

void solve(){
	int x, y;
	cin>>x>>y;
	vector<int> v(3, 0);
	v[x]++;
	v[y]++;
	for(int i = 0; i < 3; i++){
		if(v[i] > 1){
			cout<<i<<endl;
			return;
		}
	}
	for(int i = 0; i < 3; i++){
		if(v[i] == 0){
			cout<<i<<endl;
			return;
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
	t = 1;
	// cin>>t;
	while(t--) solve();

	


	return 0;
}