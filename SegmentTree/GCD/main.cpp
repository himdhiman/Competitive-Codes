#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];
int tree[N] = {0};

void build(int node, int start, int end){
	if(start == end){
		tree[node] = arr[start];
		return;
	}
	int mid = (start+end)/2;
	build(2*node, start, mid);
	build(2*node+1, mid+1, end);
	tree[node] = __gcd(tree[2*node], tree[2*node+1]);
	return;
}

void update(int node, int start, int end, int index, int value){
	if(start == end){
		tree[node] = value;
		arr[index] = value;
		return;
	}
	int mid = (start+end)/2;
	if(index <= mid){
		update(2*node, start, mid, index, value);
	}else{
		update(2*node+1, mid+1, end, index, value);
	}
	tree[node] = __gcd(tree[2*node], tree[2*node+1]);
	return;
}

int querry(int node, int start, int end, int l, int r){
	if(end < l || r < start){
		return 0;
	}
	if(l <= start and r >= end){
		return tree[node];
	}

	int mid = (start+end)/2;
	int left = querry(2*node, start, mid, l, r);
	int right = querry(2*node+1, mid+1, end, l, r);
	return __gcd(left, right);
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int n;
	cin>>n;
	for(int i = 1; i < n; i++){
		cin>>arr[i];
	}
	build(1, 1, n);
	update(1, 1, n, 3, 2);
	update(1, 1, n, 5, 2);
	cout<<querry(1, 1, n, 2, 6);

	


	return 0;
}