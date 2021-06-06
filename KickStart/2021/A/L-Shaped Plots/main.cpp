#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 105;
int r, c;
int arr[N][N], topDown[N][N], leftRight[N][N], rightLeft[N][N], bottomUp[N][N];


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int t;
	cin>>t;
	for(int x = 1; x <= t; x++){
		cin>>r>>c;
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				cin>>arr[i][j];
			}
		}
		memset(topDown, 0, sizeof topDown);
		memset(leftRight, 0, sizeof leftRight);
		memset(rightLeft, 0, sizeof rightLeft);
		memset(bottomUp, 0, sizeof bottomUp);


		//topDown

		for(int j = 0; j < c; j++){
			topDown[0][j] = arr[0][j];
		}
		for(int i = 1; i < r; i++){
			for(int j = 0; j < c; j++){
				if(arr[i][j] == 1){
					if(topDown[i-1][j] != 0){
						topDown[i][j] = topDown[i-1][j] + 1;
					}else{
						topDown[i][j] = 1;
					}
				}
			}
		}

		// bottomUp

		for(int j = 0; j < c; j++){
			bottomUp[r-1][j] = arr[r-1][j];
		}
		for(int i = r-2; i >= 0; i--){
			for(int j = 0; j < c; j++){
				if(arr[i][j] == 1){
					if(bottomUp[i+1][j] != 0){
						bottomUp[i][j] = bottomUp[i+1][j] + 1;
					}else{
						bottomUp[i][j] = 1;
					}
				}
			}
		}

		// leftRight

		for(int i = 0; i < r; i++){
			leftRight[i][0] = arr[i][0];
		}

		for(int i = 0; i < r; i++){
			for(int j = 1; j < c; j++){
				if(arr[i][j] == 1){
					if(leftRight[i][j-1] != 0){
						leftRight[i][j] = 1 + leftRight[i][j-1];
					}else{
						leftRight[i][j] = 1;
					}
				}
			}
		}


		// rightLeft

		for(int i = 0; i < r; i++){
			rightLeft[i][c-1] = arr[i][c-1];
		}

		for(int i = 0; i < r; i++){
			for(int j = c-2; j >= 0; j--){
				if(arr[i][j] == 1){
					if(rightLeft[i][j+1] != 0){
						rightLeft[i][j] = 1 + rightLeft[i][j+1];
					}else{
						rightLeft[i][j] = 1;
					}
				}
			}
		}

		// for(int i = 0; i < r; i++){
		// 	for(int j = 0; j < c; j++){
		// 		cout<<topDown[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		// cout<<endl;

		// for(int i = 0; i < r; i++){
		// 	for(int j = 0; j < c; j++){
		// 		cout<<leftRight[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		// cout<<endl;


		// for(int i = 0; i < r; i++){
		// 	for(int j = 0; j < c; j++){
		// 		cout<<bottomUp[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		// cout<<endl;

		
		int ans = 0;

		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				if(topDown[i][j] > 1){
					if(i+1 == r or topDown[i+1][j] == 0){
						if(max(leftRight[i][j], topDown[i][j]) == 2*min(topDown[i][j], leftRight[i][j]) and (j+1 == c or leftRight[i][j+1] == 0)){
							ans++;
						}else if(max(rightLeft[i][j], topDown[i][j]) == 2*min(topDown[i][j], rightLeft[i][j]) and (j-1 == 0 or rightLeft[i][j-1] == 0)){
							ans++;
						}
					}
				}

				if(bottomUp[i][j] > 1){
					
				}
			}
		}
		cout<<ans<<endl;
	}

	


	return 0;
}