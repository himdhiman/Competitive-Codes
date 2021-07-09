#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
unordered_map<int, vector<int> > m;
int arr[N];

void solve(){
	m.clear();
	int n;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>arr[i];
		m[arr[i]].push_back(i);
	}
	bool flag = true;
	for(int i = 0; i < n-1; i++){
		if(arr[i] != arr[i+1]){
			flag = false;
			break;
		}
	}
	if(flag){
		cout<<"NO"<<endl;
		return;
	}
	vector<int> visited(n, 0);
	for(int i = 0; i < n; i++){
		
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