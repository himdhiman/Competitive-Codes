#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];
int BIT[N] = {0};

void update(int val, int n, int i){
	while(i <= n){
		BIT[i] += val;
		i += (i&(-i));
	}
}

int query(int i){
	int ans = 0;
	while(i > 0){
		ans += BIT[i];
		i -= (i&(-i));
	}
	return ans;
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
		update(arr[i], n, i);
	}
	int l, r;
	cin>>l>>r;
	cout<<query(r)-query(l-1);

	


	return 0;
}