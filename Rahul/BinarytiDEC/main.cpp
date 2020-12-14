#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 


	int n;
	while((scanf("%lld", &n)) != EOF){

		int binaryNum[32]; 
  
	    int i = 0; 	
	    while (n > 0) { 
	  
	        binaryNum[i] = n % 2; 
	        n = n / 2; 
	        i++; 
	    } 
	  
	    for (int j = i - 1; j >= 0; j--){
	        cout << binaryNum[j];
	    }
	    cout<<endl;
	}

	return 0;
}