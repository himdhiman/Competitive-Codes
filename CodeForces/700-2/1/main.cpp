#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

void solve(){
	string s;
	cin>>s;
	int n = s.length();
	for(int j = 0; j < n; j++){
		if(j&1){
			for(int i = 25; i >= 0; i--){
				if(s[j] != (char)(i+'a')){
					s[j] = (char)(i+'a');
					break;
				}
			}
		}else{
			for(int i = 0; i <= 25; i++){
				if(s[j] != (char)(i+'a')){
					s[j] = (char)(i+'a');
					break;
				}
			}
		}
	}
	cout<<s<<endl;
	return;
}



int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	cin>>t;
	while(t--){
		solve();
	}

	


	return 0;
}