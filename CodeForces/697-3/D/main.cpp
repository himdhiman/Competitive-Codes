#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int a[N], b[N];

bool comp(pair<int, int> p1, pair<int, int> p2){
	if(p1.first < p2.first){
		return true;
	}else if(p1.first == p2.first){
		if(p1.second > p2.second){
			return true;
		}else{
			return false;
		}
	}
	return false;
}

void solve(){
	int n, m;
	cin>>n>>m;
	int sum = 0;
	for(int i = 0; i < n; i++){
		cin>>a[i];
		sum += a[i];
	}
	for(int i = 0; i < n; i++){
		cin>>b[i];
	}
	if(sum < m){
		cout<<-1<<endl;
		return;
	}
	vector<pair<int, int> > v;
	for(int i = 0; i < n; i++){
		v.push_back({b[i], a[i]});
	}
	sort(v.begin(), v.end(), comp);
	for(int i = 0; i < n; i++){
		cout<<v[i].first<<" ";
	}
	cout<<endl;
	for(int i = 0; i < n; i++){
		cout<<v[i].second<<" ";
	}
	cout<<endl;

	int val = 0;
	int ans = 0;
	for(int i = 0; i < n; i++){
		val += v[i].second;
		ans++;
		if(val >= m){
			break;
		}
	}
	// if(val > m){
	// 	cout<<ans<<endl;
	// 	return;
	// }
	cout<<(ans)<<endl;

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