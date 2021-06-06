#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int b, c, x, y;
	cin>>b>>c>>x>>y;
	int ans = 0;

	while(c >= x){
		ans++;
        b--;
        if(b == 0){
            cout<<ans<<endl;
            return 0;
        }
		c -= x;
	}

	while(true){
		while(c <= x){
			b--;
            if(b <= 0){
                cout<<ans<<endl;
                return 0;
            }
			c += y;
		}
		while(c >= x){
			ans++;
			b--;
            if(b <= 0){
                cout<<ans<<endl;
                return 0;
            }
			c -= x;
		}
	}

	return 0;
}