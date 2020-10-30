#include<iostream>
#include<vector>
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
		return;
	}

	int CurrMaxXor(int val){
		node * temp = root;
		int ans = 0;
		for(int i = 31; i >= 0; i--){
			int bit = (val>>i)&1;
			if(bit == 0){
				if(temp->right != NULL){
					temp = temp->right;
					ans += (1<<i);
				}else{
					temp = temp->left;
				}
			}else{
				if(temp->left != NULL){
					temp = temp->left;
					ans += (1<<i);
				}else{
					temp = temp->right;
				}
			}
		}
		return ans;
	}

	int MaxXorPair(int * arr, int start, int end){
		int ans = 0;
		vector<int> precomp;
		int x = 0;
		for(int i = start; i <= end; i++){
			precomp.push_back(x^arr[i]);
			x = x^arr[i];
		}
		for(int i = 0; i < precomp.size(); i++){
			int val = precomp[i];
			Insert(val);
			int temp = CurrMaxXor(val);
			ans = max(ans, temp);
		}
		return ans;
	}
};

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin>>n;
	int * arr = new int[n];
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}

	Trie t;
	int result = 0;
	for(int k = 1; k < n-2; k++){
		int ans1 = t.MaxXorPair(arr, 0, k);
		int ans2 = t.MaxXorPair(arr, k+1, n-1);
		int ans = ans1+ans2;
		result = max(result, ans);
	}
	cout<<result; 
}