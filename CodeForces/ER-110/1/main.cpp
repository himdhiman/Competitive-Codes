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

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int t;
	cin>>t;
	while(t--){
		int first = INT_MIN, second = INT_MIN;
		int firstIndex = -1, secondIndex = -1;
		for(int i = 0; i < 4; i++){
			cin>>arr[i];
			if(arr[i] > first){
				second = first;
				secondIndex = firstIndex;
				first = arr[i];
				firstIndex = i;
			}else if(arr[i] > second){
				second = arr[i];
				secondIndex = i;
			}
		}
		if((firstIndex < 2 and secondIndex >= 2) or (secondIndex < 2 and firstIndex >= 2)){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
		// cout<<firstIndex<<" "<<secondIndex<<endl;
	}

	


	return 0;
}