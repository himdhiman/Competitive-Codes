#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main() {
    int n, k, t, x, y;
    cin>>n>>k;
    priority_queue<ll> p;
    for(int i = 0 ; i < n; i++){
        cin>>t;
        if(t == 1){
            cin>>x>>y;
            if(p.size() >= k){
                p.pop();
            }
            p.push((x*x + y*y));
        }else{
            cout<<p.top()<<endl;
        }
    }
    return 0;
}
