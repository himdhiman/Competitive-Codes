#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 1005;
char arr[N][N];
vector<pair<int, int> > v;

bool comp(pair<int, int> a, pair<int, int> b){
	if(a.second < b.second){
		return true;
	}
	return false;
}


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int t;
	cin>>t;
	while(t--){
		v.clear();
		int n;
		cin>>n;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin>>arr[i][j];
				if(arr[i][j] == '*'){
					v.push_back({i, j});
				}
			}
		}
		// for(auto x : v){
		// 	cout<<x.first<<" "<<x.second<<endl;
		// }
		// cout<<v[0].second<<" "<<v[1].first<<endl;
		// cout<<v[1].second<<" "<<v[0].first<<endl;
		// cout<<endl;
		if(v[0].first == v[1].first){
			// int diff = abs(v[0].second-v[1].second);
			int diff = 1;
			if(v[0].first == 0){
				arr[v[0].first + diff][v[0].second] = '*';
				arr[v[1].first + diff][v[1].second] = '*';
			}else{
				arr[v[0].first - diff][v[0].second] = '*';
				arr[v[1].first - diff][v[1].second] = '*';
			}
		}else if(v[0].second == v[1].second){
			// int diff = abs(v[0].first-v[1].first);
			int diff = 1;
			if(v[0].second == 0){
				arr[v[0].first][v[0].second + diff] = '*';
				arr[v[1].first][v[1].second + diff] = '*';
			}else{
				arr[v[0].first][v[0].second - diff] = '*';
				arr[v[1].first][v[1].second - diff] = '*';
			}
		}else{
			// cout<<"HI"<<endl;
			sort(v.begin(), v.end(), comp);
			arr[v[0].first][max(v[0].second, v[1].second)] = '*';
			arr[v[1].first][min(v[0].second, v[1].second)] = '*';
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout<<arr[i][j];
			}
			cout<<endl;
		}
		// cout<<endl;
	}

	


	return 0;
}