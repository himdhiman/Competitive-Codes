#include<bits/stdc++.h>
#define int long long
using namespace std;

int dp[151][151][2];

int solve(string s, int i, int j, bool isTrue){
	//Base Cases
	if(i > j){
		return true;
	}
	if(i == j){
		if(isTrue){
			return s[i] == 'T';
		}else{
			return s[i] == 'F';
		}
	}
	if(dp[i][j][isTrue] != -1){
		return dp[i][j][isTrue];
	}

	int ans = 0;
	for(int k = i+1; k <= j-1; k += 2){
		int lt = solve(s, i, k-1 ,true);
		int lf = solve(s, i, k-1, false);
		int rt = solve(s, k+1, j, true);
		int rf = solve(s, k+1, j, false);

		if(s[k] == '|'){
			if(isTrue){
				ans += (lt*rt + lt*rf + lf*rt);
			}else{
				ans += (lf*rf);
			}
		}else if(s[k] == '&'){
			if(isTrue){
				ans += lt*rt;
			}else{
				ans += (lf*rf + lt*rf + lf*rt);
			}

		}else if(s[k] == '^'){
			if(isTrue){
				ans += (lt*rf + lf*rt);
			}else{
				ans += (lt*rt + lf*rf);
			}
		}

	}
	return dp[i][j][isTrue] = ans;
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	string s;
	getline(cin, s);
	memset(dp, -1, sizeof(dp));

	cout<<solve(s, 0, s.length()-1, true);

	return 0;
}