#include<iostream>
using namespace std;

int main(){

#ifndef ONLINE_JUDGE
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
#endif 


    int t;
    cin>>t;
    for(int x = 0; x < t; x++){
        int g;
        cin>>g;
        int ans = 0;
        for(int i = 1; i*(i-1) < 2*g; i++){
            if((2*g + i*i - i)%(2*i) == 0){
                ans++;
            }
        }
        cout<<"Case #"<<x+1<<": "<<ans<<endl;
    }
}