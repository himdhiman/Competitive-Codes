#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

void solve(){
	int minIndex = -1, maxIndex = -1;
	int minVal = INT_MAX, maxVal = INT_MIN;
	int n;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>arr[i];
		if(arr[i] < minVal){
			minVal = arr[i];
			minIndex = i;
		}
		if(arr[i] > maxVal){
			maxVal = arr[i];
			maxIndex = i;
		}
	}
	// int mask = 0;

	// int start = 0, end = n-1;
	// int turn = 0;
	// int ans1 = 0;
	// while(mask != 3){
	// 	if(!turn){
	// 		if(arr[start] == maxVal){
	// 			mask = mask | (1 << 0);
	// 		}else if(arr[start] == minVal){
	// 			mask = mask | (1 << 1);
	// 		}
	// 		start++;
	// 	}else{
	// 		if(arr[end] == maxVal){
	// 			mask = mask | (1 << 0);
	// 		}else if(arr[end] == minVal){
	// 			mask = mask | (1 << 1);
	// 		}
	// 		end--;
	// 	}
	// 	ans1++;
	// 	turn = !turn;
	// }
	// // cout<<ans1<<endl;

	// int ans2 = 0;
	// turn = 1;
	// mask = 0;
	// start = 0;
	// end = n-1;
	// while(mask != 3){
	// 	if(!turn){
	// 		if(arr[start] == maxVal){
	// 			mask = mask | (1 << 0);
	// 		}
	// 		if(arr[start] == minVal){
	// 			mask = mask | (1 << 1);
	// 		}
	// 		start++;
	// 	}else{
	// 		if(arr[end] == maxVal){
	// 			mask = mask | (1 << 0);
	// 		}
	// 		if(arr[end] == minVal){
	// 			mask = mask | (1 << 1);
	// 		}
	// 		end--;
	// 	}
	// 	ans2++;
	// 	turn = !turn;
	// }
	// cout<<ans2<<endl;

	// // cout<<min(ans1, ans2)<<endl;
	int minLeft = minIndex+1;
	int minRight = n-minIndex;
	int maxLeft = maxIndex+1;
	int maxRight = n-maxIndex;
	// cout<<minLeft<<" "<<maxLeft<<" "<<minRight<<" "<<maxRight<<endl;

	int ans1 = max(minLeft, maxLeft);
	int ans2 = max(minRight, maxRight);
	int ans3 = min(minLeft + maxRight, maxLeft + minRight);
	// cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
	// cout<<endl;
	cout<<min(ans1, min(ans2, ans3))<<endl;

	return;
}



int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	// t = 1;
	cin>>t;
	while(t--) solve();

	


	return 0;
}