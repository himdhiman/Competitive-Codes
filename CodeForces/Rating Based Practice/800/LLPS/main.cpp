#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

// const int N = 26;
// int arr[N] = {0};

void solve(){
	string s;
	cin>>s;
	int n = s.length();
	vector<int> v(26, 0);
	for(int i = 0; i < n; i++){
		v[s[i]-'a']++;
	}
	for(int i = 25; i >= 0; i--){
		if(v[i] != 0){
			for(int j = 0; j < v[i]; j++){
				cout<<(char)('a'+i);
			}
			cout<<endl;
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