#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 1000005;
int arr[N];



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int n, q;
	cin>>n>>q;
	for(int i = 1; i <= n; i++){
		cin>>arr[i];
	}
	for(int i = 0; i < q; i++){
		int t;
		cin>>t;
		if(t == 0){
			int x, y;
			cin>>x>>y;
			if(arr[y] == 0){
				cout<<"EVEN"<<endl;
			}else{
				cout<<"ODD"<<endl;
			}
		}else{
			int x;
			cin>>x;
			arr[x] = !(arr[x]);
		}
	}

	


	return 0;
}