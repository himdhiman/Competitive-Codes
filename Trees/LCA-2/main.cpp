#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 1005;
int parent[N];
int depth[N] = {0};

struct node{
	int data;
	node * left;
	node * right;

	node(int data){
		this->data = data;
		left = right = NULL;
	}
};


node * createTree(){
	int data;
	cin>>data;
	node * root = NULL;
	if(data != -1){
		root = new node(data);
	}
	queue<node *> q;
	q.push(root);
	while(!q.empty()){
		node * curr = q.front();
		q.pop();
		cin>>data;
		if(data != -1){
			curr->left = new node(data);
			q.push(curr->left);
		}
		cin>>data;
		if(data != -1){
			curr->right = new node(data);
			q.push(curr->right);
		}
	}
	return root;
}

void PrintLevelOrderZigZag(node * root){
	queue<node *> q1, q2;
	q1.push(root);
	while(!q1.empty() || !q2.empty()){
		while(!q1.empty()){
			node * curr = q1.front();
			q1.pop();
			cout<<curr->data<<" ";
			if(curr->left){
				q2.push(curr->left);
			}
			if(curr->right){
				q2.push(curr->right);
			}
		}
		cout<<endl;
		vector<int> v;
		while(!q2.empty()){
			node * curr = q2.front();
			q2.pop();
			v.push_back(curr->data);
			if(curr->left){
				q1.push(curr->left);
			}
			if(curr->right){
				q1.push(curr->right);
			}
		}
		reverse(v.begin(), v.end());
		for(auto x : v){
			cout<<x<<" "; 
		}
		cout<<endl;
	}
	return;
}

void DFS(node * root, int par, int dep){
	if(!root){
		return;
	}
	parent[root->data] = par;
	depth[root->data] = dep;
	DFS(root->left, root->data, dep+1);
	DFS(root->right, root->data, dep+1);
	return;
}

int findLCA(int a, int b, node * root){
	int depthA = depth[a];
	int depthB = depth[b];
	if(depthA > depthB){
		while(depthA != depthB){
			a = parent[a];
			depthA = depth[a];
		}
	}else if(depthA < depthB){
		while(depthA != depthB){
			b = parent[b];
			depthB = depth[b];
		}
	}
	while(parent[a] != parent[b]){
		a = parent[a];
		b = parent[b];
	}
	return parent[a];
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	node * root = createTree();
	// PrintLevelOrderZigZag(root);
	DFS(root, 0, 0);
	cout<<findLCA(4, 8, root);

	


	return 0;
}