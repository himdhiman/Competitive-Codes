#include<bits/stdc++.h>
#define int long long
using namespace std;

bool comp(int a, int b){
	return a > b;
}

void Solve(vector<int> v, vector<int> out, vector<vector<int> > &res, int sum, int n){
	if(sum == 0){
		res.push_back(out);
		return;
	}
	if(n == 0 || sum < 0){
		return;
	}
	out.push_back(v[n-1]);
	Solve(v, out, res, sum-v[n-1], n-1);
	out.pop_back();

	//exclude
	Solve(v, out, res, sum, n-1);

	return;
}


int32_t main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 

	int n;
	cin>>n;

	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin>>v[i];
	}
	sort(v.begin(), v.end(), comp);
	int sum;
	cin>>sum; 
	vector<int> out;
	vector<vector<int> > res;
	Solve(v, out, res, sum, n);
	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());
	for(auto x : res){
		for(auto y : x){
			cout<<y<<" ";
		}
		cout<<endl;
	} 




	return 0;
}