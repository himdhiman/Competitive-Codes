#include<bits/stdc++.h>
#define int long long
#define db double
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

db root(db n){
	if(n == 1){
		return 1;
	}
    db start = 0, end = n;
    for(int i = 0; i < 100005; i++){
        db mid = (start+end)/2;
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

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n%2 != 0){
			cout<<"NO"<<endl;
		}else{
			int temp = n/2;
			int sq = floor(sqrt(temp));
			// cout<<sq<<" "<<temp<<" ";
			// cout<<temp<<" ";
			if(sq*sq == temp){
				cout<<"YES"<<endl;
			}else{
				if(n%4 == 0){
					int temp2 = n/4;
					int sqTemp = floor(sqrt(temp2));
					// cout<<sqTemp<<" "<<temp2<<" ";
					if(sqTemp*sqTemp == temp2){
						cout<<"YES"<<endl;
					}else{
						cout<<"NO"<<endl;
					}
				}else{
					cout<<"NO"<<endl;
				}
			}
		}
		// cout<<endl;
	}

	


	return 0;
}