#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];
int pos = 0;

int solve(string s, int n, int i, int curr){
	if(i == n){
		if(curr == pos){
			return 1;
		}
		return 0;
	}
	if(s[i] == '+'){
		return solve(s, n, i+1, curr+1);
	}
	if(s[i] == '-'){
		return solve(s, n, i+1, curr-1);
	}
	return solve(s, n, i+1, curr+1) + solve(s, n, i+1, curr-1);
}



int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	string s1, s2;
	cin>>s1>>s2;
	for(int i = 0; i < s1.length(); i++){
		if(s1[i] == '+'){
			pos++;
		}else{
			pos--;
		}
	}
	int cnt = 0;
	for(int i = 0; i < s2.length(); i++){
		if(s2[i] == '?'){
			cnt++;
		}
	}
	double num = (1 << cnt);
	double ans = (solve(s2, s2.length(), (int)0, (int)0));
	// cout<<ans<<endl;
	if(num == 0){
		cout<<setprecision(12)<<0;
	}else{
		cout<<setprecision(12)<<(double)(ans/num);
	}

	


	return 0;
}