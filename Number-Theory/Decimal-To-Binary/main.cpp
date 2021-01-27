#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

// const int N = 100005;
// int arr[N];

// int solve(int n){

// 	return 0;
// }



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
		stack<int> arr;
		while(n > 0){
			arr.push(n%2);
			n = n/2;
		}
		while(!arr.empty()){
			cout<<arr.top();
			arr.pop();
		}
		cout<<endl;
	}

	


	return 0;
}