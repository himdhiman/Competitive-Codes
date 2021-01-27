#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	priority_queue<int> mx;
	priority_queue<int, vector<int>, greater<int> > mn;
	int n, q, val, sum = 0;
	cin>>n>>q;
	for(int i = 0; i < n; i++){
		cin>>val;
		sum += val;
		mn.push(val);
		mx.push(val);
	}
	vector<int> qry(q, 0);
	int maxim = 0;
	for(int i = 0; i < q; i++){
		cin>>qry[i];
		maxim = max(maxim, qry[i]);
	}
	// cout<<sum<<endl;
	vector<int> ans(1000000, 0);
	ans[0] = sum;
	int itr = 1;
	while(itr <= maxim){
		int mini = mn.top();
		int maxi = mx.top();
		mn.pop();
		mx.pop();
		int diff = abs(mini - maxi);
		sum = sum - mini - maxi + diff;
		mn.push(diff);
		mx.push(diff);
		ans[itr++] = sum;
	}
	for(int i = 0; i < q; i++){
		cout<<ans[qry[i]]<<endl;
	}

	


	return 0;
}