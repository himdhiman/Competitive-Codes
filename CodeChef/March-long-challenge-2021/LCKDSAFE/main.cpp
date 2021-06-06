#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 1000005;
int arr[N] = {0};

struct SparseTable{
	int n, m;
	vector<vector<int>> mat, matOR, matAND;

	SparseTable(int _n, int _m){
		n = _n;
		m = _m;
		mat.resize(n);
		matOR.resize(n);
		matAND.resize(n);
		for(int i = 0; i < n; i++){
			mat[i].resize(m);
			matOR[i].resize(m);
			matAND[i].resize(m);
		}
	}

	void build(){
		for(int i = 0; i < n; i++){
			mat[i][0] = arr[i];
			matOR[i][0] = arr[i];
			matAND[i][0] = arr[i];
		}
		for(int j = 1; j < m; j++){
			for(int i = 0; i + (1 << j) <= n; i++){
				mat[i][j] = max(mat[i][j-1], mat[i+(1<<(j-1))][j-1]);
				matOR[i][j] = (matOR[i][j-1] | matOR[i+(1<<(j-1))][j-1]);
				matAND[i][j] = ((matAND[i][j-1]) & (matAND[i+(1<<(j-1))][j-1]));

			}
		} 
	}

	vector<int> Query(int l, int r){
		int ans = INT_MIN;
		bool flag = true;
		int bitOR = 0;
		int bitAnd = 1;
		for(int i = m; i >= 0; i--){
			if(l + (1<<i) - 1 <= r){
				if(flag){
					bitOR = matOR[l][i];
					bitAnd = matAND[l][i];
					flag = false;
				}else{
					bitOR = (bitOR | matOR[l][i]);
					bitAnd = (bitAnd & matAND[l][i]);
				}
				ans = max(ans, mat[l][i]);
				l += (1<<i);
			}
		}
		return {ans, bitOR, bitAnd};
	}
	
};


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}
		int m = ceil(log2(n)) + 1;
		SparseTable s(n, m);
		s.build();
		int ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = i; j <= n; j++){
				vector<int> q = s.Query(i-1, j-1);
				if(((q[1])^(q[2])) >= q[0]){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}