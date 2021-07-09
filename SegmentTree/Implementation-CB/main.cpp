#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];
int tree[N];

void buildTree(int node, int start, int end){
	if(start ==  end){
		tree[node] = arr[start];
		return;
	}
	int mid = (start + end)/2;
	buildTree(2*node, start, mid);
	buildTree(2*node+1, mid+1, end);
	tree[node] = min(tree[2*node], tree[2*node+1]);
	return;
}

int query(int node, int start, int end, int l, int r){
	if(r < start || l > end){
		return INT_MAX;
	}
	if(l <= start and r >= end){
		return tree[node];
	}
	int mid = (start + end)/2;
	int left = query(2*node, start, mid, l, r);
	int right = query(2*node+1, mid+1, end, l, r);
	return min(left, right);
}

void updatePoint(int node, int start, int end, int index, int value){
	if(index < start || index > end){
		return;
	}
	if(start == end){
		tree[node] = value;
		return;
	}
	int mid = (start + end)/2;
	updatePoint(2*node, start, mid, index, value);
	updatePoint(2*node+1, mid+1, end, index, value);
	tree[node] = min(tree[2*node], tree[2*node+1]);
	return;
}

void updateRange(int node, int start, int end, int l, int r, int val){
	if(r < start || l > end){
		return;
	}
	if(l <= start and r >= end){
		tree[node] = val;
		return;
	}
	int mid = (start+end)/2;
	updateRange(2*node, start, mid, l, r, val);
	updateRange(2*node+1, mid+1, end, l, r, val);
	tree[node] = min(tree[2*node], tree[2*node+1]);
	return;
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
	buildTree(1, 1, n);
	cout<<query(1, 1, n, 9, 9)<<endl;
	updatePoint(1, 1, n, 9, -10);
	cout<<query(1, 1, n, 9, 9)<<endl;

	return 0;
}