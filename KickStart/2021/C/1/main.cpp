#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

bool ispallindrome(string s, int start, int end){
	while(start <= end){
		if(s[start++] != s[end--]){
			return false;
		}
	}
	return true;
}

int power(int x, int y, int p)
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
	for(int x = 0; x < t; x++){
		int n, k;
		string s;
		cin>>n>>k;
		cin>>s;
		vector<int> v;
		if(n&1){
			for(int i = 0; i < n/2 + 1; i++){
				v.push_back(min((int)(s[i]-'a'+1), k));			}
		}else{
			for(int i = 0; i < n/2 ; i++){
				v.push_back(min((int)(s[i]-'a'+1), k));
			}
		}
		for(auto x : v){
			cout<<x<<" ";
		}
		cout<<endl;
		int ans = 0;
		for(int i = 0; i < v.size()-1; i++){
			ans += ((v[i]-1)*power(k, v.size()-i-1, MOD))%MOD;
		}
		ans += v[v.size()-1]%MOD;
		cout<<"Case #"<<x+1<<": ";
		if(ispallindrome(s, 0, n-1)){
			string temp = "";
			for(int i = 0; i < n; i++){
				temp += (char)('a' + k-1);
			}
			if(temp < s){
				cout<<ans%MOD<<endl;
			}else{
				cout<<(ans-1)%MOD<<endl;
			}
		}else{
			cout<<(ans)%MOD<<endl;
		}
	}

	


	return 0;
}