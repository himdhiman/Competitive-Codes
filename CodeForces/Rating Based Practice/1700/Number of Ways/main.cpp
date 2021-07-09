#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 500005;
int arr[N];

void solve(){
	int n;
	cin>>n;
	int sum = 0;
	for(int i = 0; i < n; i++){
		cin>>arr[i];
		sum += arr[i];
	}
	if((sum%3) != 0){
		cout<<0<<endl;
		return;
	}
	sum = sum/3;
	vector<int> start, end;
	int curr = 0;
	for(int i = 0; i < n; i++){
		curr += arr[i];
		if(curr == sum){
			start.push_back(i);
		}
	}
	curr = 0;
	for(int i = n-1; i >= 0; i--){
		curr += arr[i];
		if(curr == sum){
			end.push_back(i);
		}
	}
	reverse(end.begin(), end.end());
	// for(int i = 0; i < start.size(); i++){
	// 	cout<<start[i]<<" ";
	// }
	// cout<<endl;
	// for(int i = 0; i < end.size(); i++){
	// 	cout<<end[i]<<" ";
	// }
	cout<<endl;
	int ans = 0;
	for(int i = 0; i < start.size(); i++){
		int temp = start[i]+1;
		auto ub = upper_bound(end.begin(), end.end(), temp);
		ans += (end.end()-ub);
	}
	cout<<ans<<endl;

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