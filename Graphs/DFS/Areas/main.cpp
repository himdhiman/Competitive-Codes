#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 1005;
int r, c;
int visited[N][N];
char arr[N][N];

bool isValid(int i, int j){
	if(i >= 0 and i < r and j >= 0 and j < c and visited[i][j] == 0){
		return true;
	}
	return false;
}

void DFS(int x, int y, int &len){
	visited[x][y] = 1;
	len++;
	if(isValid(x+1, y)){
		DFS(x+1, y, len);
	}
	if(isValid(x-1, y)){
		DFS(x-1, y, len);
	}
	if(isValid(x, y+1)){
		DFS(x, y+1, len);
	}
	if(isValid(x, y-1)){
		DFS(x, y-1, len);
	}
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int t;
	cin>>t;
	while(t--){
		cin>>r>>c;
		memset(visited, 0, sizeof visited);
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				cin>>arr[i][j];
				if(arr[i][j] == '#'){
					visited[i][j] = 1;
				}
			}
		}
		vector<int> res;
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				if(visited[i][j] == 0){
					int len = 0;
					DFS(i, j, len);
					res.push_back(len);
				}
			}
		}
		cout<<res.size()<<endl;
		for(auto x : res){
			cout<<x<<" ";
		}
		cout<<endl;
	}
	


	return 0;
}