#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int t;
	cin>>t;
	while(t--){
		int n, e, h, a, b, c;
		cin>>n>>e>>h>>a>>b>>c;
		vector<int> dp;
		vector<int> dp_Helper;
		for(int i = 0; i <= (n+1); i++){
			dp_Helper.push_back(i);
		}

		for(int i = 0; i <= n; i++){
			int idx1 = lower_bound(dp_Helper.begin(), dp_Helper.end(), 2*n-e-2*i)-dp_Helper.begin();
			int idx2 = upper_bound(dp_Helper.begin(), dp_Helper.end(), h-3*i)-dp_Helper.begin()-1;
			if(idx2 < idx1 || idx1 == n+1){
				continue;
			}
			if(idx2 == n+1 and idx2+3*i > h){
				continue;
			}

			int k;
			if(c > a) k = (idx1 < (n-i) ? idx1 : (n-i));
			else k = (idx2 < (n-i) ? idx2 : (n-i));

			int o = n-k-i;
			if(k+2*i >= 2*n-e and k + 3*i <= h){
				dp.push_back(a*o + b*i + c*k);
			}
		}
		if(dp.size() == 0){
			cout<<-1<<endl;
		}else{
			int mn = INT_MAX;
			for(int i = 0; i < dp.size(); i++){
				mn = min(mn, dp[i]);
			}
			cout<<mn<<endl;
		}
		
	}



	return 0;
}