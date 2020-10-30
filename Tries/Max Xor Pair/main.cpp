#include<iostream>
using namespace std;

class node{
public:
	node * left;
	node * right;

	node(){
		left = right = NULL;
	}
};

class Trie{
public:

	node * root;

	Trie(){
		root = new node();
	}

	void Insert(int val){
		node * temp = root;
		for(int i = 31; i >= 0; i--){
			int bit = (val>>i)&1;
			if(bit == 1){
				if(temp->right == NULL){
					temp->right = new node();
					temp = temp->right;
				}else{
					temp = temp->right;
				}
			}else{
				if(temp->left == NULL){
					temp->left = new node();
					temp = temp->left;
				}else{
					temp = temp->left;
				}
			}
		}
	}

	int CurrentmaxXor(int val){
		node * temp = root;
		int ans = 0;
		for(int i = 31; i >= 0; i--){
			int bit = (val>>i)&1;
			if(bit == 1){
				if(temp->left != NULL){
					temp = temp->left;
					ans += (1<<i);
				}else{
					temp = temp->right;
				}
			}else{
				if(temp->right != NULL){
					temp = temp->right;
					ans += (1<<i);
				}else{
					temp = temp->left;
				}
			}
		}
		return ans;
	}
	int maxXor(int arr[], int n){
		int ans = 0;
		for(int i = 0; i < n; i++){
			int val = arr[i];
			Insert(val);
			int temp = CurrentmaxXor(val);
			ans = max(ans, temp); 
		}
		return ans;
	}
};


int main(){

#ifndef INLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	Trie t;
	cout<<t.maxXor(arr, n);
}