#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 26;
int parent[N];

int find(int x){
	if(parent[x] == x){
		return x;
	}
	return parent[x] = find(parent[x]);
}

void unite(int x, int y){
	int p1 = find(x);
	int p2 = find(y);

	if(p1 != p2){
		if(p1 > p2){
			parent[p1] = p2;
		}else{
			parent[p2] = p1;
		}
	}
}




int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	for(int i = 0; i < N; i++){
		parent[i] = i;
	}
	
	string a, b, c;
	getline(cin, a);
	getline(cin, b);
	getline(cin, c);

	for(int i = 0; i < a.length(); i++){
		int x = a[i] - 'a';
		int y = b[i] - 'a';
		unite(x, y);
	}
	for(int i = 0; i < N; i++){
		find(i);
	}

	string result = "";
	for(int i = 0; i < c.length(); i++){
		int ans = parent[c[i]-'a'];
		result += (char)(ans + 'a');
	}
	cout<<result;


	return 0;
}