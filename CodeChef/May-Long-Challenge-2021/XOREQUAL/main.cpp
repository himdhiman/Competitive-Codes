#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;


int solve(int x, int y, int p)
{
    int res = 1;     
    x = x % p; 
    if (x == 0) return 0; 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;   
        y = y>>1; 
        x = (x*x) % p;
    }
    return res;
}



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
		int ans = solve(2, n-1, MOD);
		cout<<(ans)<<endl;
	}

	


	return 0;
}