#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int a[N], b[N];

void solve(){
	int A, B, n;
	cin>>A>>B>>n;
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	for(int i = 0; i < n; i++){
		cin>>b[i];
	}
	int C = 0, D = 0;
	for(int i = 0; i < n; i++){
		// if(B <= 0){
		// 	break;
		// }
		// int temp1 = b[i]/A;  				// --> fights to kill monster
		// if((b[i]%A != 0)) temp1++;
		// int temp2 = B/a[i];					// --> fights to kill hero
		// if((B%a[i]) != 0) temp2++;
		// // if(temp1 > temp2){
		// // 	cout<<"NO"<<endl;
		// // 	return;
		// // }else{
		// // 	B -= temp1*a[i];
		// // }
		// int mn = min(temp1, temp2);
		// B -= (mn)*a[i];
		// b[i] -= (mn)*A;
		C += a[i];
		D += b[i];
	}
	int temp1 = D/A;  				// --> fights to kill monster
	if((D%A != 0)) temp1++;
	int temp2 = B/C;					// --> fights to kill hero
	if((B%C) != 0) temp2++;
	if(temp1 > temp2){
		cout<<"NO"<<endl;
		return;
	}else{
		cout<<"YES"<<endl;
		return;
	}
	// if(b[n-1] > 0){
	// 	cout<<"NO"<<endl;
	// 	return;
	// }
	// cout<<"YES"<<endl;
	// return;
}



int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	// t = 1;
	cin>>t;
	while(t--) solve();

	


	return 0;
}