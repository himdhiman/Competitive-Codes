#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N] = {0};
int tree[N] = {0};

void build(int node, int start, int end){
	if(start == end){
		tree[node] = arr[start]; 
		return;
	}
	int mid = (start+end)/2;
	build(2*node, start, mid);
	build(2*node+1, mid+1, end);
	tree[node] = tree[2*node] + tree[2*node+1];
	return;
}

int query(int node, int start, int end, int l, int r){
	if(l <= start and r >= end){
		return tree[node];
	}
	if(r < start or end < l){
		return 0;
	}

	int mid = (start + end)/2;
	int left = query(2*node, start, mid, l, r);
	int right = query(2*node+1, mid+1, end, l, r);
	return (left+right);
}

void update(int node, int start, int end, int index, int val){
	if(start == end){
		tree[node] = val;
		arr[index] = val;
		return;
	}
	int mid = (start + end)/2;
	if(index <= mid){
		update(2*node, start, mid, index, val);
	}else{
		update(2*node+1, mid+1, end, index, val);
	}
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
	update(1, 1, n, 5, 1);
	cout<<query(1, 1, n, 3, 7);



	


	return 0;
}