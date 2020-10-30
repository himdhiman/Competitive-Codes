#include<iostream>
#include <climits>
#include<string>
#include <vector>
using namespace std;

string LCS(string s1, string s2, int l1, int l2){
	int dp[l1+1][l2+1];

	for(int i = 0; i <= l1; i++){
		for(int j = 0; j <= l2; j++){
			if(i == 0 || j == 0){
				dp[i][j] = 0;
			}else if(s1[i-1] == s2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	string ans = "";
	int x = l1, y = l2;
	while(x > 0 && y > 0){
		if(s1[x-1] == s2[y-1]){
			ans += s1[x-1];
			x--;
			y--;
		}else if(dp[x-1][y] > dp[x][y-1]){
			x--;
		}else{
			y--;
		}
	}
	int start = 0;
	int end = ans.length()-1;
	while(start <= end){
		swap(ans[start++], ans[end--]);
	}

	return ans;
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);

	cout<<LCS(s1, s2, s1.length(), s2.length())<<'\n';

	return 0;
}