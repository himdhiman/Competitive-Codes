#include<bits/stdc++.h>
#define int long long
using namespace std;

struct node{
	int data;
	node * next;

	node(int data){
		this->data = data;
		next = NULL;
	}
};

node * CreateLL(int n){
	int data;
	node * head = NULL;
	if(head == NULL){
		cin>>data;
		head = new node(data);
	}
	node * it = head;
	for(int i = 1; i < n; i++){
		cin>>data;
		node * temp = new node(data);
		it->next = temp;
		it = it->next;
	}
	return head;
}

void Print(node * head){
	while(head){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
	return;
}

node * Reverse(node * head){
	if(head == NULL){
		return NULL;
	}
	if(head->next == NULL){
		return head;
	}
	node * newHead = Reverse(head->next);
	node * c = head;
	c->next->next = c;
	c->next = NULL;
	return newHead;
}



int32_t main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 

	int n;
	cin>>n;
	node * head = CreateLL(n);
	Print(head);
	node * rev = Reverse(head);
	Print(rev);
	return 0;
}