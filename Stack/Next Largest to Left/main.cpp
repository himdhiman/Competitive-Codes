#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];


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

	stack<int> s;
	for(int i = 0; i < n; i++){
		if(s.empty()){
			cout<<-1<<" ";
		}else{
			int curr = s.top();
			while(!s.empty() and curr < arr[i]){
				s.pop();
				if(!s.empty()){
					curr = s.top();
				}
			}
			if(s.empty()){
				cout<<-1<<" ";
			}else{
				cout<<curr<<" ";
			}
		}
		s.push(arr[i]);
	}


	return 0;
}