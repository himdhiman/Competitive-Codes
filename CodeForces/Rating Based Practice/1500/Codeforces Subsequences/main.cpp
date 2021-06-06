#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

// const int N = 100005;
// int arr[N];

// int solve(int n){

// 	return 0;
// }



int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int n;
	cin>>n;
	string s = "codeforces";
	string t = "";
	for(int i = 0; i < n-1; i++){
		t += 's';
	}
	cout<<s+t<<endl;

	


	return 0;
}