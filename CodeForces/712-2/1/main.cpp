#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

bool ispall(string s){
	int start = 0, end = s.length()-1;
	while(start <= end){
		if(s[start++] != s[end--]){
			return false;
		}
	}
	return true;
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		bool flag = true;
		int n = s.length();
		for(int i = 0; i < n; i++){
			if(s[i] != 'a'){
				flag = false;
				break;
			}
		}
		if(flag){
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
		if(!ispall("a"+s)){
			cout<<"a"+s<<endl;
		}else{
			cout<<s+"a"<<endl;
		}
		// cout<<"a"+s<<endl;
	}

	


	return 0;
}