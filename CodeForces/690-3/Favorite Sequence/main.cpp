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
		int n;
		cin>>n;
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}
		int start = 0;
		int end = n-1;
		while(1){
			if(start + 1 == end){
				cout<<arr[start]<<" "<<arr[end];
				break;
			}else if(start == end){
				cout<<arr[start];
				break;
			}else{
				cout<<arr[start]<<" "<<arr[end]<<" ";
			}
			start++;
			end--;
		}
		cout<<endl;
	}
	


	return 0;
}