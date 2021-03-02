#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N] = {0};
int tree[N] = {0};

void build(int node, int start, int end){
	if(start == end){
		tree[start] = arr[start];
		return;
	}
	int mid = (start+end)/2;
	build(2*node, start, mid);
	build(2*node+1, mid+1, end);
	tree[node] = tree[2*node] + tree[2*node + 1];
}

int query(int node, int start, int end, int l, int r){
	if(end < l || r < start){
		return 0;
	}
	if(l <= start and end <= r){
		return tree[node];
	}
	int mid = (start+end)/2;
	int left = query(2*node, start, mid, l, r);
	int right = query(2*node + 1, mid+1, end, l, r);
	return (left+right);
}

void update(int node, int start, int end, int l, int r, int val){
	if(end < l || r < start || end < start){
		return;
	}
	if(start == end){
		tree[start] += val;
		return;
	}
	int mid = (start+end)/2;
	update(2*node, start, mid, l, r, val);
	update(2*node+1, mid+1, end, l, r, val);
	tree[node] = tree[2*node] + tree[2*node + 1];
	return;
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int n;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}

	


	return 0;
}