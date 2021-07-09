#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

int primeFactors(int n1, int n2)
{
	int ans = 0;
    while (n1 % 2 == 0)
    {
        ans++;
        n1 = n1/2;
    }
    while (n2 % 2 == 0)
    {
        ans++;
        n2 = n2/2;
    }
 
    for (int i = 3; i*i <= max(n1,n2); i = i + 2)
    {
        while (n1 % i == 0)
        {
            ans++;
            n1 = n1/i;
        }
        while (n2 % i == 0)
        {
            ans++;
            n2 = n2/i;
        }
    } 
    if (n1 > 2)
        ans++;
    if (n2 > 2)
        ans++;

    return ans;
}

void solve(){
	int a, b, k;
	cin>>a>>b>>k;
	int low = 2;
	int high = primeFactors(a, b);
	if(a != b and (max(a, b)%min(a, b) == 0)){
		low = 1;
	}
	if(k <= high and k >= low){
		cout<<"YES"<<endl;
		return;
	}
	cout<<"NO"<<endl;
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
	// t = 1;
	cin>>t;
	while(t--) solve();

	


	return 0;
}