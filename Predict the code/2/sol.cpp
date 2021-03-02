#include<bits/stdc++.h>
#define int long long
#define db long double
#define MOD 1000000007
using namespace std;

const int N = 1000005;
int arr[N];

db root(db n){
    db start = 0, end = n;
    for(int i = 0; i < 50; i++){
        db mid = (start+end)/2;
        if(mid*mid <= n){
            start = mid;
        }else{
            end = mid;
        }
    }
    return start;
}


void solve(){
	arr[1] = 1;
	for(int i = 2; i <= N; i++){
		arr[i] = arr[i-1] + arr[(int)root(i)];
	}
	return;
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	solve();
	int t, n;
	cin>>t;
	while(t--){
        cin >> n;
        if(n < 0 || n > 1e6) cout << "INVALID\n";
        else cout << arr[n] << endl;
    }


	return 0;
}