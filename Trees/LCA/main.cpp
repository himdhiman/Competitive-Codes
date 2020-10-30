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

node * CreateTree(){
    node * root = NULL;
    int data;
    cin>>data;
    if(data != -1){
        root = new node(data); 
    }
    queue<node * >q;
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

void PreOrder(node * root){
	if(!root){
		return;
	}
	cout<<root->data<<" ";
	PreOrder(root->left);
	PreOrder(root->right);
	return; 
}

bool PrintPath(node * root, vector<int> &path, int k){
	if(!root){
		return false;
	}
	path.push_back(root->data);
	if(root->data == k){
		return true;
	}
	if(PrintPath(root->left, path, k) || PrintPath(root->right, path, k)){
		return true;
	}
	path.pop_back();
	return false;
}

node * GetAddress(node * root, int target){
    if(root->data == target){
    	return root;
    }
    queue<node *> q;
    q.push(root);
    node * ans = NULL;
    while(!q.empty()){
    	node * curr = q.front();
    	q.pop();
    	if(curr->left){
	    	if(curr->left->data == target){
	    		ans = curr->left;
	    		break;
	    	}else{
	    		q.push(curr->left);
	    	}
    	}
    	if(curr->right){
    		if(curr->right->data == target){
    			ans = curr->right;
    			break;
    		}else{
    			q.push(curr->right);
    		}
    	}

    }
    return ans;
}


int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	node * root = CreateTree();
	PreOrder(root);
	cout<<'\n';
	vector<int> path_a, path_b;
	bool ans1 = PrintPath(root, path_a, 7);
	bool ans2 = PrintPath(root, path_b, 8);
	for(auto x : path_a){
		cout<<x<<" "; 
	}
	cout<<endl;
	for(auto x : path_b){
		cout<<x<<" ";
	}
	cout<<endl;
	int start1 = 0;
	int start2 = 0;
	while(path_a[start1] == path_b[start2]){
		start1++;
		start2++;
	}
	int lca = path_a[start1-1];
	cout<<lca<<endl;
	node * nodeAdd = GetAddress(root, lca);
	cout<<nodeAdd->data<<endl;
	return 0;
}