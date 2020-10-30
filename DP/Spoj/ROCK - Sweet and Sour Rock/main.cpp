#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 200;
vector<int> arr(N, 0); 

bool isValid(int s, int e){
	int sweet = 0, sour = 0;
	for(int i = s; i <= e; i++){
		if(arr[i] == 1){
			sweet++;
		}else{
			sour++;
		}
	}
	return sweet > sour;
}

int solve(int i, int j){
	if(i >= j){
		return 0;
	}
	if(isValid(i, j)){
		return 0;
	}
	int ans = LLONG_MAX;
	for(int k = i; k < j; k++){
		int temp = 1 + solve(i, k) + solve(k+1, j);
		ans = min(ans, temp);
	}
	return ans;
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t, n;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}
		cout<<solve(0, n-1)<<endl;
		fill(arr.begin(), arr.end(), 0);
	}
	


	return 0;
}