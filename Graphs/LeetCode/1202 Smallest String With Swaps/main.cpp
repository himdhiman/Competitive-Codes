#include<bits/stdc++.h>
using namespace std;
    
const int N = 100005;
int parent[N];
int RanK[N];

int find(int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find(parent[x]);
}

void unite(int p1, int p2){
    
    if(RanK[p1] < RanK[p2]){
        parent[p1] = p2;
        RanK[p2] += RanK[p1];
    }else{
        parent[p2] = p1;
        RanK[p1] += RanK[p2];
    }
    return;
}

string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
    int n = s.length();
    for(int i = 0; i < n; i++){
        parent[i] = i;
        RanK[i] = 1;
    }
    for(auto x : pairs){
        int p1 = find(x[0]);
        int p2 = find(x[1]);
        if(p1!=p2){
            unite(p1, p2);
        }
    }
    for(int i = 0; i < 10; i++) cout<<find(i)<<endl;
    unordered_map<int, priority_queue<char, vector<char>, greater<char> > > m;
    for(int i = 0; i < n; i++){
        m[find(i)].push(s[i]);
    }
    string res = "";
    for(int i = 0; i < n; i++){
        int curr = find(i);
        res += m[curr].top();
        m[curr].pop();
    }
    return res;
}

int32_t main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 

	string s;
	getline(cin, s);
	int n;
	cin>>n;
	vector<vector<int> > pairs;
	for(int i = 0; i < n; i++){
		int u, v;
		cin>>u>>v;
		pairs.push_back({u, v});
	}

	string res = smallestStringWithSwaps(s, pairs);
	cout<<res;
    // cout<<parent[2];

	return 0;
}