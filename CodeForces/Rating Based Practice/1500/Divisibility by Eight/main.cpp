#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

int solve(int n){

	return 0;
}



int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	string s;
	cin>>s;
	int n = s.length();
	for(int i = 0; i < n; i++){
		if((s[i]-'0') % 8 == 0){
			cout<<"YES"<<endl;
			cout<<s[i]<<endl;
			return 0;
		}
	}
	if(n == 1){
		cout<<"NO"<<endl;
		return 0;
	}
	for(int i = 1; i < n; i++){
		if(s[i]-'0' != 0){
			for(int j = 0; j < i; j++){
				int num = (s[j]-'0')*10 + (s[i]-'0');
				if(num % 8 == 0){
					cout<<"YES"<<endl;
					cout<<num<<endl;
					return 0;
				}
			}
		}
	}
	if(n == 2){
		cout<<"NO"<<endl;
		return 0;
	}
	for(int i = 0; i < n-2; i++){
		if(s[i] != '0'){
			for(int j = i+1; j < n-1; j++){
				for(int k = j+1; k < n; k++){
					int num = (s[i]-'0')*100 + (s[j]-'0')*10 + (s[k]-'0');
					if(num % 8 == 0){
						cout<<"YES"<<endl;
						cout<<num<<endl;
						return 0;
					}
				}
			}
		}
	}
	cout<<"NO"<<endl;

	


	return 0;
}