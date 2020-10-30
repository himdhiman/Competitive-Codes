#include<bits/stdc++.h>
#define int long long
using namespace std;

class node{
	char data;
	unordered_map<char, node*> children;
	bool isEnding;

	node(char data){
		this->data = data;
		isEnding = false;
	}
};

class Trie{
	node * root;
	int ans = 0;

	Trie(){
		root = new node('\0');
	}

	void Insert(string s){
		node * temp = root;
		for(int i = 0; i < s.length(); i++){
			char curr = s[i];
			if(temp->children.find(curr) == temp->children.end()){
				node * var = new node(curr);
				temp->children[curr] = var;
				temp = temp->children[curr];
			}else{
				temp = temp->children[curr];
			}
		}
		temp->isEnding = true;
		return;
	}	

};

int Solve(node * root, string s, int pos){
	for(auto x : root->children){
		if(s[pos] == x.first){
			ans++;
		}
	}
}



int32_t main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 

	int n;
	cin>>n;

	Trie t;
	string s;
	getline(cin, s);
	vector<string> v(n);
	for(int i = 0; i < n; i++){
		getline(cin, s);
		t.Insert(s);
		cin>>v[i];
	}





	return 0;
}