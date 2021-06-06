#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int A[N];
int B[N];

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
		int n, m;
		cin>>n>>m;
		for(int i = 0; i < n; i++){
			cin>>A[i];
		}
		for(int j = 0; j < m; j++){
			cin>>B[j];
		}
		vector<int> right(n, -1), left(n, -1);
		int curr = -1;
		for(int i = n-1; i >= 0; i--){
			// if(A[i] != 0){
			// 	right[i] = i;
			// }
			if(A[i] == 2){
				curr = i;
			}
			// if(A[i] == 0){
			// 	right[i] = curr;
			// }
			right[i] = curr;
		
		}
		curr = -1;
		for(int i = 0; i < n; i++){
			// if(A[i] != 0){
			// 	left[i] = i;
			// }
			if(A[i] == 1){
				curr = i;
			}
			// if(A[i] == 0){
			// 	left[i] = curr;
			// }
			left[i] = curr;
		
		}
		for(auto x : left){
			cout<<x<<" ";
		}
		cout<<endl;
		for(auto x : right){
			cout<<x<<" ";
		}
		cout<<endl;
		for(int i = 0; i < m; i++){
			if(A[B[i]-1] != 0 || B[i] == 1){
				cout<<0<<" ";
			}else{
				int toReach = B[i]-1;
				int ans = 0;
				if(left[toReach] == -1 and right[toReach] == -1){
					ans = -1;
				}else if(left[toReach] == -1){
					ans = abs(right[toReach] - toReach);
				}else if(right[toReach] == -1){
					ans = abs(left[toReach] - toReach);
				}else{
					ans = min(abs(right[toReach] - toReach), abs(left[toReach] - toReach));
				}
				cout<<ans<<" ";
			}
		}
		cout<<endl;
	}
	


	return 0;
}