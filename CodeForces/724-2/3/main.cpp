#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];


int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		map<pair<int, int> , int> m; 
		int cd = 0, ck = 0;
		for(int i = 0; i < n; i++){
			if(s[i] == 'D'){
				cd++;
			}else{
				ck++;
			}
			int x = cd;
			int y = ck;
			int temp = __gcd(x, y);
			x /= temp;
			y /= temp;
			m[{x, y}]++;
			cout<<m[{x, y}]<<" ";
		}
		cout<<endl;
	}

	


	return 0;
}