#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 1000005;
int arr[N];
int sieve[N];
int tree[4*N];

void Sieve(){
	for(int i = 0; i < N; i++){
		sieve[i] = i;
	}
	for(int i = 2; i*i < N; i++){
		if(sieve[i] == i){
			for(int j = i*i; j < N; j+=i){
				sieve[j] = i;
			}
		}
	}
}

void build(int node, int start, int end){
	if(start == end){
		tree[node] = sieve[arr[start]];
		return;
	}
	int mid = (start + end)/2;
	build(2*node, start, mid);
	build(2*node+1, mid+1, end);
	tree[node] = max(tree[2*node], tree[2*node+1]);
	return;
}

void update(int node, int start, int end, int l, int r){
	if(r < start || l > end || r < l){
		return;
	}
	if(tree[node] == 1){
		return;
	}
	if(start == end){
		arr[start] = arr[start]/sieve[arr[start]]; 
		tree[node] = sieve[arr[start]];
		return;
	}
	int mid = (start + end)/2;
	update(2*node, start, mid, l, r);
	update(2*node+1, mid+1, end, l, r);
	tree[node] = max(tree[2*node], tree[2*node+1]);
	return;
}

int query(int node, int start, int end, int l, int r){
	if(r < start || l > end || r < l){
		return INT_MIN;
	}
	if(l <= start and r >= end){
		return tree[node];
	}
	int mid = (start + end)/2;
	int left = query(2*node, start, mid, l, r);
	int right = query(2*node+1, mid+1, end, l, r);
	return max(left, right);
}





int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	Sieve();
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		for(int i = 1; i <= n; i++){
			cin>>arr[i];
		}
		build(1, 1, n);
		// for(int i = 1; i <= 4*n; i++){
		// 	cout<<tree[i]<<" ";
		// }
		int a, u, v;
		for(int i = 0; i < m; i++){
			cin>>a>>u>>v;
			if(a == 0){
				update(1, 1, n, u, v);
			}else{
				cout<<max((int)1, query(1, 1, n, u, v))<<" ";
			}
		}
		cout<<endl;
	}

	


	return 0;
}