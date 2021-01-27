#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;




int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	priority_queue<int> pq;
	int n, val, q;
	cin>>n;
	while(n--){
		cin>>val;
		pq.push(val);
	}
	cin>>q;
	int a, b;
	while(q--){
		cin>>a;
		if(a == 1){
			cin>>b;
			pq.push(b);
		}else{
			cout<<pq.top()<<endl;
		}
	}

	return 0;
}