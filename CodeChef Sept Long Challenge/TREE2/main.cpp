#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t, n, val;
	cin>>t;
	while(t--){
	    cin>>n;
	    set<int> s;
	    for(int i = 0; i < n; i++){
	        cin>>val;
	        s.insert(val);
	    }
	    auto it = s.begin();
	    if(*it == 0){
	    	cout<<s.size()-1<<endl;
	    }else{
	    	cout<<s.size()<<endl;
	    }
	    
	}
	return 0;
}
