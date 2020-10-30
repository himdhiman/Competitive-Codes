#include<bits/stdc++.h>
#define int long long
using namespace std;

struct node{
	int data;
	node * left;
	node * right;

	node(int data){
		this->data = data;
		left = right = NULL;
	}
};

void CreateTree(node *& root){
	int data;
	if(root == NULL){
		cin>>data;
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
}

void Preorder(node * root){
	if(!root){
		return;
	}
	cout<<root->data<<" ";
	Preorder(root->left);
	Preorder(root->right);
	return;
}

void Inorder(node * root){
	if(!root){
		return;
	}
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
	return;
}

void PostOrder(node * root){
	if(!root){
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	cout<<root->data<<" ";
	return;
}

void LevelOrder(node * root){
	queue<node *> q1, q2;
	q1.push(root);

	while(!q1.empty() and q2.empty()){
		bool isTrue = true;
		while(!q1.empty()){
			node * curr = q1.front();
			if(isTrue){
				cout<<curr->data<<" ";
			}
			isTrue = !isTrue;
			q1.pop();
			if(curr->left){
				q2.push(curr->left);
			}
			if(curr->right){
				q2.push(curr->right);
			}
		}
		cout<<endl;
		bool isTrue2 = true;
		while(!q2.empty()){
			node * curr = q2.front();
			if(isTrue2){
				cout<<curr->data<<" ";
			}
			isTrue2 = !isTrue2;
			q2.pop();
			if(curr->left){
				q1.push(curr->left);
			}
			if(curr->right){
				q1.push(curr->right);
			}
		}
		cout<<endl;
	}
}


int32_t main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 

		node * root = NULL;
		CreateTree(root);
		Preorder(root);
		cout<<endl;
		LevelOrder(root);





	return 0;
}