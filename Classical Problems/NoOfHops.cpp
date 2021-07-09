#include <iostream>
using namespace std;

long long int NoOfHops(int n){
    if(n == 0){
        return 1;
    }
    if(n < 0){
        return 0;
    }
    long long int a = NoOfHops(n-1);
    long long int b = NoOfHops(n-2);
    long long int c = NoOfHops(n-3);
    return (a+b+c);
}

long long int NoOfHopsDP(int n){
    long long int dp0 = 0;
    long long int dp1 = 0;
    long long int dp2 = 1;
    long long int ans;
    for(long long int i = 1; i <= n; i++){
        ans = (dp0 % 1000000007 + dp1 % 1000000007 + dp2 % 1000000007) % 1000000007;
        dp0 = dp1;
        dp1 = dp2;
        dp2 = ans;
    }
    return ans;
}

int main() {
    cout<<NoOfHopsDP(4);
}
