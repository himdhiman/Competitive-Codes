#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 1000001;
int arr[N], tree[2*N];

void build(int node, int start, int end){
	if(start == end){
		tree[node] = arr[start];
		return;
	}
	int mid = (start + end)/2;
	build(2*node, start, mid);
	build(2*node+1, mid+1, end);

	int power = log2(end-start+1);
	if(power&1){
		tree[node] = (tree[2*node] | tree[2*node+1]);
	}else{
		tree[node] = (tree[2*node] ^ tree[2*node+1]);
	}
	return;
}


void update(int node, int start, int end, int index, int val){
	if(index < start or index > end){
		return;
	}
	if(start == end){
		tree[node] = val;
		return;
	}
	int mid = (start+end)/2;
	update(2*node, start, mid, index, val);
	update(2*node+1, mid+1, end, index, val);
	int power = log2(end-start+1);
	if(power&1){
		tree[node] = (tree[2*node] | tree[2*node+1]);
	}else{
		tree[node] = (tree[2*node] ^ tree[2*node+1]);
	}

}


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int n, q;
	cin>>n>>q;
	n = pow(2, n);
	for(int i = 1; i <= n; i++){
		cin>>arr[i];
	}
	build(1, 1, n);
	while(q--){
		int idx, val;
		cin>>idx>>val;
		update(1, 1, n, idx, val);
		cout<<tree[1]<<endl;
	}
	return 0;
}