#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

set<string> st;

void solve(string s, int i, int n){
	if(i == n){
		st.insert(s);
		// cout<<s<<endl;
		return;
	}
	for(int j = i; j < n; j++){
		swap(s[i], s[j]);
		solve(s, i+1, n);
		swap(s[i], s[j]);
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
	string s;
	cin>>s;
	// cout<<s<<" ";
	int n = s.length();
	int i = 0;
	solve(s, i, n);
	for(auto x : st){
		cout<<x<<" ";
	}

	


	return 0;
}