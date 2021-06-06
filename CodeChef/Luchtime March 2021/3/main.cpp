#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

vector<int> NML(int n){
	vector<int> res;
	stack<pair<int, int > > s;
	for(int i = 0; i < n; i++){
		if(s.empty()){
			res.push_back(-1);
		}else{
			auto curr = s.top();
			bool flag = false;
			while(!s.empty() and curr.first <= arr[i]){
				s.pop();
				if(s.empty()){
					res.push_back(-1);
					flag = true;
					break;
				}
				curr = s.top();
			}
			if(!flag){
				res.push_back(curr.second);
			}
		}
		s.push({arr[i], i});
	}
	return res;
}

vector<int> NMR(int n){
	vector<int> res;
	stack<pair<int, int> > s;
	for(int i = n-1; i >= 0; i--){
		if(s.empty()){
			res.push_back(-1);
		}else{
			auto curr = s.top();
			bool flag = false;
			while(!s.empty() and curr.first <= arr[i]){
				s.pop();
				if(s.empty()){
					res.push_back(-1);
					flag = true;
					break;
				}
				curr = s.top();
			}
			if(!flag){
				res.push_back(curr.second);
			}
		}
		s.push({arr[i], i});
	}
	reverse(res.begin(), res.end());
	return res;
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
		vector<int> l = NML(n);
		vector<int> r = NMR(n);

		vector<int> res;
		for(int i = 0; i < n; i++){
			int cnt = 0;
			for(int start = i-1; start >= max((int)0, l[i]); start--){
				if(arr[start] == arr[i]){
					cnt++;
				}
			}
			for(int start = i+1; start <= ((r[i] != -1 )? r[i] : (n-1)); start++){
				if(arr[start] == arr[i]){
					cnt++;
				}
			}
			res.push_back(cnt);
		}
		for(auto x : res){
			cout<<x<<" ";
		}
		cout<<endl;
	}

	


	return 0;
}