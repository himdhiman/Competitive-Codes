#include<bits/stdc++.h>
using namespace std;


int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t, n;
	cin>>t;
	while(t--){
		cin>>n;
		vector<int> v(n);
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin>>v[i];
		}
		for(int i = 0; i < n; i++){
			int l, r, x = 0, y = 0;
			for(l = i; l >= 0; l--){
				if(v[l] > v[i]){
					x++;
				}
			}
			for(r = i; r < n; r++){
				if(v[r] < v[i]){
					y++;
				}
			}
			a[i] = x+y;
		}




	return 0;
}