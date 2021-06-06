#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

set<string> s;

int dp[1000];

int solve(string word, int start, int end){
	if(start == end){
		return true;
	}
	if(dp[start] != -1){
		return dp[start];
	}
	for(int i = start+1; i <= word.size(); i++){
		if(s.find(word.substr(start, i-start)) != s.end() and solve(word, i, end)){
			return dp[start] = true;
		}
	}
	return dp[start] = false;
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int n;
	cin>>n;
	string str;
	for(int i = 0; i < n; i++){
		cin>>str;
		s.insert(str);
	}
	memset(dp, -1, sizeof dp);
	string word = "samsungandmango";
	cout<<solve(word, 0, word.length())<<endl;

	


	return 0;
}