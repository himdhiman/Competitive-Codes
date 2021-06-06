#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

int getPos(int arr[], int start, int end, int n){
	if(start > end){
		return -1;
	}
	int mid = start + (end - start)/2;
	int next = (mid+1)%n;
	int prev = (mid-1+n)%n;
	cout<<mid<<" "<<start<<" "<<end<<endl;
	if(arr[mid] < arr[next] and arr[mid] < arr[prev]){
		return mid;
	}else if(arr[mid] >= arr[start]){
		return getPos(arr, mid+1, end, n);
	}else{
		return getPos(arr, start, mid-1, n);
	}
}




int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int n;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	// if(arr[0] < arr[n-1]){
	// 	cout<<0;
	// }else{
	// 	int pivot = getPos(arr, 0, n-1, n);
	// 	cout<<pivot<<endl;
	// }
	int pivot = getPos(arr, 0, n-1, n);
	cout<<pivot<<endl;



	return 0;
}