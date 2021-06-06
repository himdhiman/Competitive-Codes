#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 1000005;
int arr[N], tree[N];

void build(int node, int start, int end){
	if(start == end){
		tree[node] = arr[start];
		return;
	}
	int mid = (start + end)/2;
	build(2*node, start, mid);
	build(2*node+1, mid+1, end);
	tree[node] = tree[2*node] + tree[2*node+1];
}

void update(int node, int start, int end, int val, int index){
	if(index < start || index > end){
		return;
	}
	if(start == end){
		tree[node] = val;
		return;
	}
	int mid = (start + end)/2;
	update(2*node, start, mid, val, index);
	update(2*node+1, mid+1, end, val, index);
	tree[node] = tree[2*node] + tree[2*node+1];
}

int query(int node, int start, int end, int l, int r){
	if(r < start || l > end || r < l){
		return 0;
	}
	if(l <= start and r >= end){
		return tree[node];
	}
	int mid = (start + end)/2;
	int left = query(2*node, start, mid, l, r);
	int right = query(2*node+1, mid+1, end, l, r);
	return (left+right);
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int n, q, l, r, t;
	cin>>n>>q;
	for(int i = 1; i <= n; i++){
		cin>>arr[i];
	}
	build(1, 1, n);
	while(q--){
		cin>>t>>l>>r;
		if(t == 1){
			update(1, 1, n, r, l);
		}else{
			cout<<query(1, 1, n, l, r)<<endl;
		}
	}

	return 0;
}