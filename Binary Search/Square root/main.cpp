#include<bits/stdc++.h>
#define int long long
#define db double
#define MOD 1000000007
using namespace std;

int getSqrt(int start, int end, int x){
	if(x < 2){
		return x;
	}
	int ans = 1;
	while(start <= end){
		int mid = start + (end-start)/2;
		if(mid*mid <= x){
			start = mid+1;
			ans = max(ans, mid);
		}else{
			end = mid-1;
		}
	}
	return ans;
}

db root(db n){
    db start = 0, end = n;
    for(int i = 0; i < 50; i++){
        db mid = start + (end - start)/2;
        if(mid*mid <= n){
            start = mid;
        }else{
            end = mid;
        }
    }
    return start;
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int n;
	cin>>n;
	int start = 1, end = n/2;
	cout<<getSqrt(start, end, n)<<" "<<root(n);

	


	return 0;
}