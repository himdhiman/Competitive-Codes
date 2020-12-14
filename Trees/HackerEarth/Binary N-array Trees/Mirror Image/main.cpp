#include<bits/stdc++.h>
#define int long long
using namespace std;

struct node{
	int data;
	node * left;
	node * right;

	node(int data){
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

// map<int, pair<int, int> > m;

node * GetAddress(node * root, int target){
    if(!root){
        return NULL;
    }
    if(root->data == target){
        return root;
    }
    GetAddress(root->left, target);
    GetAddress(root->right, target);
    return NULL;
}

void PreOrder(node * root){
	if(!root){
		return;
	}
	cout<<root->data<<" ";
	PreOrder(root->left);
	PreOrder(root->right);
	return;
}




int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int e, q;
	cin>>e>>q;
	node * root = new node(1);
	for(int i = 0; i < 3; i++){
		int u, v;
		char pos;
		cin>>u>>v>>pos;
		node * tar = GetAddress(root, u);
		cout<<tar<<endl;
		if(pos == 'R'){
			tar->right = new node(v);
		}else{
			tar->left = new node(v);
		}
	}
	// PreOrder(root);
	


	return 0;
}