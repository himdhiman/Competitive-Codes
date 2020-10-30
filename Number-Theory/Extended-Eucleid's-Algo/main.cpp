#include<bits/stdc++.h>
#define int long long
using namespace std;

int x, y, GCD;

void ExtendedEucleid(int a, int b){
	if(b == 0){
		x = 1;
		y = 0;
		GCD = a;
		return;
	}
	ExtendedEucleid(b, a%b);
	int cx = y;
	int cy = x-(a/b)*y;

	x = cx;
	y = cy;
}



int32_t main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 

	// 18x + 30y = 6
	ExtendedEucleid(18, 30);
	cout<<x<<" "<<y<<endl;




	return 0;
}