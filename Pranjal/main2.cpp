#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input2.txt", "r", stdin);
		freopen("output2.txt", "w", stdout);
	#endif

	int n;
	cin>>n;
	string arr[n][2*n-1];
	for(int i = 0; i < n; i++){
		for(int j = 0; j <  (2*n-1); j++){
			arr[i][j] = "*";
		}
	}
	bool flag = true;
	int start = 1;
	int cnt = 0;
	for(int i = 0; i < n/2;i++){
		for(int j = 0; j < n; j++){
			arr[i][2*j] = to_string(start);
			start++;
		}
		for(int j = 0; j < n; j++){
			arr[n-i-1][2*j] = to_string(start);
			start++;
		}
	}
	if(n%2 != 0){
		int i = (n/2);
		for(int j = 0; j < n; j++){
			arr[i][2*j] = to_string(start);
			start++;
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j <  (2*n-1); j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}