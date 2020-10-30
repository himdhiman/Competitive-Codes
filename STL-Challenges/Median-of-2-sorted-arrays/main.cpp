#include<bits/stdc++.h>
#define int long long
#define INT_MAX LLONG_MAX
#define INT_MIN LLONG_MIN
using namespace std;



int32_t main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 

	int n;
	cin>>n;

	vector<int> A(n), B(n);

	for(int i = 0; i < n; i++){
		cin>>A[i];
	}
	for(int i = 0; i < n; i++){
		cin>>B[i];
	}

	int n1 = n;
	int n2 = n;

	int start = 0;
	int end = n1;

	while(start <= end){
		int i = (start + end)/2;
		int j = (n1 + n2 + 1)/2 - i;

		int maxLeftX, minRightX, maxLeftY, minRightY;
		if(i > 0){
			maxLeftX = A[i-1];
		}else{
			maxLeftX = INT_MIN;
		}
		if(i < n1){
			minRightX = A[i];
		}else{
			minRightX = INT_MAX;
		}
		if(j > 0){
			maxLeftY = B[j-1];
		}else{
			maxLeftY = INT_MIN;
		}
		if(j < n2){
			minRightY = B[j];
		}else{
			minRightY = INT_MAX;
		}

		if(maxLeftY <= minRightX and maxLeftX <= minRightY){
			if((n1 + n2) % 2 == 0){
				int ans = (max(maxLeftX, maxLeftY) + min(minRightX, minRightY))/2;
				cout<<ans;
				break;
			}else{
				int ans = max(maxLeftY, maxLeftX);
				cout<<ans;
				break;
			}
		}else if(maxLeftX > minRightY){
			end = i-1;
		}else{
			start = i+1;
		}
	}



	return 0;
}