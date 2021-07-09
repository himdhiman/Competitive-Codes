#include <bits/stdc++.h>
using namespace std;

long long int Catalan(int n){
    long long int ans = 1;
    for(int i = 1; i <= n; i++){
        ans = ans*(n+i);
        ans /= i; 
    }
    ans /= (n+1);
    return ans;
}

int main() {
    cout<<Catalan(3);
}
