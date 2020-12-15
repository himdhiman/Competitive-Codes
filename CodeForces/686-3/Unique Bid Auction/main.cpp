#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 200005;
int arr[N];
int freq[N] = {0};


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		memset(freq, 0, sizeof freq);
		for(int i = 0; i < n; i++){
			cin>>arr[i];
			freq[arr[i]]++;
		}
		int ans = -1;
		for(int i = 0; i < N; i++){
			if(freq[i] == 1){
				ans = i;
				break;
			}
		}
		if(ans == -1){
			cout<<-1<<endl;
		}else{	
			for(int i = 0; i < n; i++){
				if(arr[i] == ans){
					cout<<i+1<<endl;
					break;
				}
			}
		}
	}

	


	return 0;
}