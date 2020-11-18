#include<bits/stdc++.h>
#define int long long
using namespace std;


int solve(vector<vector<int> > mat, int i, int j){
	if(i == mat.size()){
		return 0;
	}
	int ans = 0;
	for(int k = 0; k < mat[0].size(); k++){
		if(k != i){
			ans = max(mat[i][k] + )
		}
	}
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		vector<vector<int> > mat(n, vector<int>(0, m));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin>>mat[i][j];
			}
		}
	}

	


	return 0;
}