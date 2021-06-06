#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 400005;
int arr[N];


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int t;
	cin>>t;
	while(t--){
		int n, m, val;
		cin>>n>>m;
		for(int i = 0; i < m; i++){
			cin>>arr[i];
		}
		if(n == 0){
			cout<<0<<endl;
			continue;
		}
		int start = m;
		for(int i = 0; i < m; i++){
			arr[start++] = arr[i];
		}
		unordered_map<int, int> mp;
		int ansleft = 0;
		for(int i = m-1; i >= 0; i--){
			if(arr[i] >= 1 and arr[i] <= n){
				mp[arr[i]]++;
			}
			if(mp.size() == n){
				ansleft = m-i-1;
				break;
			}
		}
		ansleft++;
		mp.clear();
		int ansright = 0;
		for(int i = 0; i < m ; i++){
			if(arr[i] >= 1 and arr[i] <= n){
				mp[arr[i]]++;
			}
			if(mp.size() == n){
				ansright = i;
				break;
			}
		}
		ansright++;
		mp.clear();

		vector<pair<int, int> > p;
		start = 0;
		int end = 0;
		while(end < 2*m){
			if(arr[end] >= 1 and arr[end] <= n){
				mp[arr[end]]++;
			}
			if(mp.size() == n){
				while(arr[start] < 1 || arr[start] > n){
					start++;
				}
				while(mp.size() == n){
					p.push_back({start, end});
					if(arr[start] >= 1 and arr[start] <= n){
						mp[arr[start]]--;
						if(mp[arr[start]] == 0){
							mp.erase(mp.find(arr[start]));
						}
					}
					start++;
				}
			}
			end++;

		}
		// cout<<ansleft<<endl;
		// cout<<ansright<<endl;
		// for(auto x : p){
		// 	cout<<x.first<<" "<<x.second<<endl;
		// }
		int ans3 = INT_MAX;
		for(auto x : p){
			if(x.second >= m and x.first <= m-1){
				ans3 = min(ans3, x.second-x.first+1);
			}
		}
		cout<<min(ans3, min(ansleft, ansright))<<endl;
	}

	return 0;
}