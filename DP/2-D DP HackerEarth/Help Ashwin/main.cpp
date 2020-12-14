#include<bits/stdc++.h>
#define int long long
using namespace std;




int solve(vector<vector<int> > mat, int start, int i, int j){
	if(i == mat.size()){
		return 0;
	}
	for(int k = start; k < mat[0].size(); k++){
		if(k != j){
			int temp2 = mat[i][k] + solve(mat, 0, i+1, k);
			int temp1 = solve(mat, k+1, i, j);
			return max(temp1, temp2);
		}
	}
	return 0;
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
		vector<vector<int> > mat(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin>>mat[i][j];
			}
		}
		// memset(dp, -1, sizeof dp);
		cout<<solve(mat, 0, 0, -1)<<endl;
	}

	


	return 0;
}