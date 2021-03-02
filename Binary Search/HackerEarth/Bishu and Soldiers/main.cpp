#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];
int pref[N];

int index(int n, int target){
	int l = 0, r = n-1;
	int ans = 0;
	while(l <= r){
		int mid = (l + r)/2;
		if(arr[mid] <= target){
			ans = mid;
			l = mid+1;
		}else{
			r = mid-1;
		}
	}
	return ans;
}




int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int n, q, var;
	cin>>n;
	int sum = 0;
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	sort(arr, arr+n);
	for(int i = 0; i < n; i++){
		sum += arr[i];
		pref[i] = sum;
	}
	cin>>q;
	while(q--){
		cin>>var;
		int ind = index(n, var);
		cout<<ind+1<<" "<<pref[ind]<<endl;
	}



	


	return 0;
}