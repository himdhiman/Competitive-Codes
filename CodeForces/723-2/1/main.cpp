#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;



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
		n = 2*n;
		int arr[n];
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}
		int cnt = 0;
		int pos = 1;
		while(cnt != n){
			int prev = (pos-1+n)%n;
			int next = (pos+1)%n;
			if((arr[prev] + arr[next]) != 2*arr[pos]){
				cnt++;
				pos = next;
			}else{
				int temp = arr[prev];
				arr[prev] = arr[pos];
				arr[pos] = temp;
				cnt = 0;
			}

		}
		for(int i = 0; i < n; i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;

	}

	


	return 0;
}