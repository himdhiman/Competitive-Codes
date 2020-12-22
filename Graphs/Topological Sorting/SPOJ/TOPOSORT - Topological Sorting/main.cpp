#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
vector<int> gr[N];
int indegree[N] = {0};
priority_queue<int, vector<int>, greater<int> > q;



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int v, e, x, y;
	cin>>v>>e;
	for(int i = 0; i < e; i++){
		cin>>x>>y;
		indegree[y]++;
		gr[x].push_back(y);
	}
	for(int i = 1; i <= v; i++){
		if(indegree[i] == 0){
			q.push(i);
		}
	}
	vector<int> arr;
	while(!q.empty()){
		int curr = q.top();
		q.pop();
		arr.push_back(curr);
		for(auto x : gr[curr]){
			indegree[x]--;
			if(indegree[x] == 0){
				q.push(x);
			}
		}
	}
	if(arr.size() == v){
		for(int i = 0; i < arr.size(); i++){
			cout<<arr[i]<<" "; 
		}
	}else{
		cout<<"Sandro fails.";
	}
	

	


	return 0;
}