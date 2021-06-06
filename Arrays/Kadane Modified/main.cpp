#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

int solve(int n){
	int start = 0, end = 0, temp = 0;
	int sum = 0, csum = 0;

	for(int i = 0; i < n; i++){
		csum += arr[i];
		if(csum < 0){
			csum = 0;
			temp = i+1; 
		}
		if(csum > sum){
			sum = csum;
			start = temp;
			end = i;
		}
	}
	cout<<start<<" "<<end<<endl;
	return sum;
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int n;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	cout<<solve(n);

	


	return 0;
}