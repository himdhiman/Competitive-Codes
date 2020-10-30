#include<bits/stdc++.h>
#define int long long int
using namespace std;



int32_t main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 

		int n, k, t, x, y;
	    cin>>n>>k;
	    priority_queue<int> p;
	    for(int i = 0 ; i < n; i++){
	        cin>>t;
	        if(t == 1){
	            cin>>x>>y;
	            int dist = (x*x + y*y);
	            if(p.size() < k){
	            	p.push(dist);
	            }else if(p.top() > dist){
	            	p.pop();
	            	p.push(dist);
	            }
	        }else{
	            cout<<p.top()<<endl;
	        }
	    }
	return 0;
}