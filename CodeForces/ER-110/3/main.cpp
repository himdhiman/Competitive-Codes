#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

int solve(string s, int n, int prev, vector<int> &v){
	if(n == 0){
		v.push_back(prev);
		return 1;
	}

	if((s[n-1] == '1' and prev == 1) or (s[n-1] == '0' and prev == 0)){
		return solve(s, n-1, prev);
	}

	// exclude
	int ans1 = solve(s, n-1, prev);

	// include
	int ans2 = 0;
	v.push_back(prev);
	if(s[n-1] == '?'){
		if(prev == 0){
			ans1 = solve(s, n-1, 1);
		}else{
			ans2 = solve(s, n-1, 0);
		}
	}else{
		ans1 = solve(s, n-1, !prev); 
	}
	v.pop_back();
	return ans1+ans2;
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		vector<int> v;
		cout<<solve(s, s.length(), 0, v) + solve(s, s.length(), 1, v)<<endl;
	}
	


	return 0;
}