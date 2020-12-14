#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];
set<int> s;

void solve(int n, int sum){
	if(n == 0){
		s.insert(sum);
		return;
	}
	solve(n-1, sum);
	solve(n-1, sum+arr[n-1]);
	return;
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}
		solve(n, 0);
		cout<<s.size()<<endl;
		s.clear();
	}
	


	return 0;
}