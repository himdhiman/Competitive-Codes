#include<bits/stdc++.h>
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

void AddElementBST(node *& root, int data){
	if(root == NULL){
		root = new node(data);
		return;
	}
	node * prev = NULL;
	node * it = root;
	while(it){
		if(it->data > data){
			prev = it;
			it = it->left;
		}else{
			prev = it;
			it = it->right;
		}
	}
	if(prev->data > data){
		prev->left = new node(data);
	}else{
		prev->right = new node(data);
	}
	return;
}

node * CreateFromSortedList(vector<int> input, int start, int end){
	if(start > end){
		return 0;
	}
	int mid = (start + end)/2;
	node * root = new node(input[mid]);
	root->left = CreateFromSortedList(input, start, mid-1);
	root->right = CreateFromSortedList(input, mid+1, end);
	return root;
}

bool SearchElement(node * root, int element){
	if(!root){
		return false;
	}
	if(root->data == element){
		return true;
	}
	if(root->data > element){
		return SearchElement(root->left, element);
	}else{
		return SearchElement(root->right, element);
	}
}

void ReturnMin(node * root){
	while(root->left){
		root = root->left;
	}
	cout<<root->data<<endl;
	return;
}

bool isBST(node * root){
	static int minimum = INT_MIN;
	if(!root){
		return true;
	}
	bool left = isBST(root->left);
	if(root->data < minimum){
		return false;
	}
	minimum = root->data;
	bool right = isBST(root->right);
	return left && right;
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

int CountNodes(node * root){
	if(!root){
		return 0;
	}
	int left = CountNodes(root->left);
	int right = CountNodes(root->right);
	return left+right+1;
}

int heightBST(node * root){
	if(!root){
		return 0;
	}
	int left = heightBST(root->left);
	int right = heightBST(root->right);
	return max(left, right)+1;
}

int DiameterHelper(node * root, int &res){
	if(!root){
		return 0;
	}
	int left = DiameterHelper(root->left, res);
	int right = DiameterHelper(root->right, res);

	int temp = max(left, right) + 1;
	int ans = max(temp, left+right+1);
	res = max(res, ans);

	return temp;
}

int Diameter(node * root){
	int res = INT_MIN;
	int var = DiameterHelper(root, res);
	return res;
}

int MaxSumPathAnytoAnyHelper(node * root, int &res){
	if(!root){
		return 0;
	}
	int left = MaxSumPathAnytoAnyHelper(root->left, res);
	int right = MaxSumPathAnytoAnyHelper(root->right, res);

	int temp = max(root->data + max(left, right), root->data);
	int ans = max(temp, left+right+root->data);
	res = max(ans, res);
	return temp;
}

int MaxSumPathAnytoAny(node * root){
	int res = INT_MIN;
	int var = MaxSumPathAnytoAnyHelper(root, res);
	return res;
}

int MaxSumPathLeafToLeafHelper(node * root, int &res){
	if(!root){
		return 0;
	}
	int left = MaxSumPathLeafToLeafHelper(root->left, res);
	int right = MaxSumPathLeafToLeafHelper(root->right, res);

	int temp = max(left, right) + root->data;
	if(root->right == NULL && root->left == NULL){
		temp = max(temp, root->data);
	}
	int ans = max(temp, left+right+root->data);
	res = max(ans, res);
	return temp;
}

int MaxSumPathLeafToLeaf(node * root){
	int res = INT_MIN;
	int var = MaxSumPathLeafToLeafHelper(root, res);
	return res;
}

void InOrder(node * root){
	if(!root){
		return;
	}
	InOrder(root->left);
	cout<<root->data<<" ";
	InOrder(root->right);
	return;
}

void LevelOrder(node * root){
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
		while(!q2.empty()){
			node * curr = q2.front();
			q2.pop();
			cout<<curr->data<<" ";
			if(curr->left){
				q1.push(curr->left);
			}
			if(curr->right){
				q1.push(curr->right);
			}
		}
		cout<<endl;
	}
	return;
}



int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, val;
	vector<int> input;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>val;
		input.push_back(val);
	}
	node * root = CreateFromSortedList(input, 0, n-1);
	InOrder(root);
	cout<<endl;
	AddElementBST(root, 2);
	AddElementBST(root, 6);
	AddElementBST(root, 10);
	AddElementBST(root, 20);
	AddElementBST(root, 30);
	// AddElementBST(root, 0);
	// AddElementBST(root, -1);
	// AddElementBST(root, -2);

	InOrder(root);
	cout<<endl;
	LevelOrder(root);

	cout<<SearchElement(root, 20)<<" "<<SearchElement(root, 9)<<" "<<SearchElement(root, 8)<<endl;
	ReturnMin(root);
	cout<<isBST(root)<<endl;
	cout<<CountNodes(root)<<endl;
	cout<<heightBST(root)<<endl;
	cout<<Diameter(root)<<endl;

	cout<<MaxSumPathAnytoAny(root)<<endl;
	cout<<MaxSumPathLeafToLeaf(root)<<endl;

	return 0;
}