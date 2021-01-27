#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];
int tree[N] = {0};

void build(int node, int start, int end){
	if(start == end){
		tree[node] = 1;
		return;
	}
	int mid = (start+end)/2;
	build(2*node, start, mid);
	build(2*node+1, mid+1, end);
	if(tree[2*node] < tree[2*node+1]){
		tree[node] = tree[2*node] + tree[2*node+1];
	}else{
		tree[node] = max(tree[2*node], tree[2*node+1]);
	}
	return;
}

void query(int node, int start, int end, int l, int r){
	if(end < l || r < start){
		return 0;
	}
	if(l <= start and r >= end){
		return tree[node];
	}
	int mid = (start+end)/2;
	int left = query(2*node, start, mid, l, r);
	int right = query(2*node+1, mid+1, end, l, r);

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

	


	return 0;
}