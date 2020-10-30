#include<bits/stdc++.h>
#define int long long
using namespace std;

int dp[100][100][100];

int solve(vector<pair<int, int> > v, int z, int o, int n){
    if(n == 0 || (z <= 0 and o <= 0)){
        return 0;
    }   
    if(dp[n][z][o] != -1){
    	return dp[n][z][o];
    }
    if(v[n-1].first > z || v[n-1].second > o){
        solve(v, z, o, n-1);
    }
    return dp[n][z][o] = max(1 + solve(v, z-v[n-1].first, o-v[n-1].second, n-1), solve(v, z, o, n-1));
}
    
    
int findMaxForm(vector<string>& strs, int m, int n) {
    vector<pair<int, int> > p;
    for(int i = 0; i < strs.size(); i++){
        int z = 0, o = 0;
        for(int j = 0; j < strs[i].length(); j++){
            if(strs[i][j] == '0'){
                z++;
            }else{
                o++;
            }
        }
        p.push_back({z, o});
    }
    // for(auto x : p) cout<<x.first<<" "<<x.second<<endl;
    memset(dp, -1, sizeof dp);
    int s = p.size();
    int ans = solve(p, m, n, s);
    return ans;
}



int32_t main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 


	int t, n, m;
	cin>>t;
	vector<string> strs;
	string s;
	getline(cin, s);
	for(int i = 0; i < t; i++){
		getline(cin, s);
		strs.push_back(s);
	}
	cin>>m>>n;
	cout<<findMaxForm(strs, m, n);


	return 0;
}