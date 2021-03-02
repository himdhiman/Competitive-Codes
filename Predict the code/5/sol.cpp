#include<bits/stdc++.h>
#define int long long
using namespace std;



int getSetBitsFromOneToN(int N){
    int two = 2,ans = 0;
    int n = N;
    while(n){
        ans += (N/two)*(two>>1);
        if((N&(two-1)) > (two>>1)-1) ans += (N&(two-1)) - (two>>1)+1;
        two <<= 1;
        n >>= 1;
    }
    return ans;
}


int32_t main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif 

    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        if(n < 0){
            cout<<"INVALID"<<endl;   
        }else{
            cout<<getSetBitsFromOneToN(n)<<endl;   
        }  
    }

    return 0;
}