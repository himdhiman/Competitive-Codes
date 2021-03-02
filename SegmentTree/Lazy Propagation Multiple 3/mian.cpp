#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];
int tree[N];
int lazy[N] = {0};

void build(int node, int start, int end){
	if(start == end){
		if(arr[start] % 3 == 0){
			tree[node] = 1;
		}else{
			tree[node] = 0;
		}
		return;
	}
	int mid = (start + end)/2;
	build(2*node, start, mid);
	build(2*node+1, mid+1, end);
	tree[node] = tree[2*node] + tree[2*node + 1];
	return;
}

int query(int node, int start, int end, int l, int r){
	if(start > r or end < l or start > end){
		return 0;
	}
	if(lazy[node] != 0){
		int diff = lazy[node];
		lazy[node] = 0;
		tree[node] = (end-start+1)*diff;
		if(start != end){
			lazy[2*node] += diff;
			lazy[2*node+1] += diff;
		}
	}
	if(l <= start and r >= end){
		return tree[node];
	}
	int mid = (start + end)/2;
	int left = query(2*node, start, mid, l, r);
	int right = query(2*node + 1, mid+1, end, l, r);
	return (left+right);
}

void update(int node, int start, int end, int l, int r, int inc){
	if(lazy[node] != 0){
		int diff = lazy[node];
		lazy[node] = 0;
		tree[node] += (end-start+1)*diff;
		if(start != end){
			lazy[2*node] += diff;
			lazy[2*node + 1] + diff; 
		}
	}
	if(start > r or end < l or start > end){
		return;
	}
	if(l <= start and r >= end){
		tree[node] += (end - start + 1)*inc;
		if(start != end){
			lazy[2*node] += inc;
			lazy[2*node + 1] += inc;
		}
		return;
	}
	int mid = (start + end)/2;
	update(2*node, start, mid, l, r, inc);
	update(2*node+1, mid+1, end, l, r, inc);
	tree[node] = tree[2*node] + tree[2*node+1];
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int n;
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>arr[i];
	}	
	build(1, 1, n);
	update(1, 1, n, 1, n, 1);
	cout<<query(1, 1, n, 1, n);

	return 0;
}