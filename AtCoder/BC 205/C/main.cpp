#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

// const int N = 100005;
// int arr[N];

// int getPow(int a, int b){
// 	if(b == 0){
// 		return 1;
// 	}
// 	if(b%2 == 0){
// 		return getPow(a, b/2)*getPow(a, b/2);
// 	}
// 	return a*getPow(a, b/2)*getPow(a, b/2);
// }


void solve(){
	int a, b, c;
	cin>>a>>b>>c;
	bool isnegA = false;
	bool isnegB = false;

	if(a < 0){
		isnegA = true;
	}
	if(b < 0){
		isnegB = true;
	}
	a = abs(a);
	b = abs(b);

	if(c&1){
		if(isnegA and isnegB){
			if(a > b){
				cout<<"<";
			}else if(b > a){
				cout<<">";
			}else{
				cout<<"=";
			}
		}else if(isnegA){
			cout<<"<";
		}else if(isnegB){
			cout<<">";
		}else{
			if(a > b){
				cout<<">";
			}else if(b > a){
				cout<<"<";
			}else{
				cout<<"=";
			}
		}
	}else{
		if(a > b){
			cout<<">";
		}else if(b > a){
			cout<<"<";
		}else{
			cout<<"=";
		}
	}

	return;
}



int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	t = 1;
	// cin>>t;
	while(t--) solve();

	


	return 0;
}