#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	cin>>t;
	while(t--){
		int n, x;
		cin>>n>>x;
		int sum = 0;
		for(int i = 0; i < n; i++){
			cin>>arr[i];
			sum += arr[i];
		}
		if(sum == x){
			cout<<"NO"<<endl;
		}else{
			cout<<"YES"<<endl;
			int end = n-1, start = 0;
			int temp = 0;
			while(start <= end){
				if(temp + arr[end] != x){
					cout<<arr[end]<<" ";
					temp += arr[end];
					end--;
				}else{
					cout<<arr[start]<<" ";
					temp += arr[start];
					start++; 
				}
			}
			cout<<endl;
		}
	}

	


	return 0;
}