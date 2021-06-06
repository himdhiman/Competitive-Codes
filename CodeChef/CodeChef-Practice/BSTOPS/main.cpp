#include<bits/stdc++.h>
#define int long long
using namespace std;

struct Node{
	int val;
	Node * left;
	Node * right;

	Node(int val){
		this->val = val;
		left = right = NULL;
	}
};


void Insert(int val, Node * &root){
	if(!root){
		root = new Node(val);
		return;
	}
	Node * it = root;
	Node * prev = NULL;
	while(it){
		if(it->val < val){
			//right
			prev = it;
			it = it->right;
		}else{
			//left
			prev = it;
			it = it->left;
		}
	}
	if(prev->val > val){
		prev->left = new Node(val);
	}else{
		prev->right = new Node(val);
	}
	return;
}

Node * Delete(int val, Node * root){
	if(!root){
		return NULL;
	}
	if(root->val == val){
		// no child
		if(!root->left && !root->right){
			delete root;
			return NULL;
		}

		// single child
		else if((!root->left && root->right) || (root->left && !root->right)){
			Node * temp;
			if(root->left){
				temp = root->left;
			}else{
				temp = root->right;
			}
			delete root;
			return temp;
		}

		// double child
		else{
			Node * parent = root;
			Node * it = root->left;
			while(it->right){
				parent = it;
				it = it->right;
			}
			if(root != parent){
				parent->right = it->left;
				it->left = root->left;
				it->right = root->right;
			}
			delete root;
			return it;
		}
	}
	if(root->val > val){
		root->left = Delete(val, root->left);
	}else{
		root->right = Delete(val, root->right);
	}
	return root;
}

static int ans = 0;

void Find(int val, Node * root, int& temp){
	if(val == root->val){
		ans = temp;
		return;
	}else if(val < root->val){
		int var = 2*temp;
		Find(val, root->left, var);
	}else{
		int var = 2*temp+1;
		Find(val, root->right, var);
	}
	return;
}


int32_t main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 

	int q;
	cin>>q;

	Node * root = NULL;
	while(q--){
		char o;
		int val;
		cin>>o>>val;
		if(o == 'i'){
			Insert(val, root);
			int temp = 1;
			Find(val, root, temp);
			cout<<ans<<endl;
		}else{
			int temp = 1;
			Find(val, root, temp);
			root = Delete(val, root);
			cout<<ans<<endl;
		}
	}

	return 0;
}