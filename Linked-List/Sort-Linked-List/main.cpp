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

node * createLL(int n){
	node * head = NULL;
	int data;
	if(head == NULL){
		cin>>data;
		head = new node(data);
	}
	node * it = head;
	for(int i = 1; i < n; i++){
		cin>>data;
		it->next = new node(data);
		it = it->next;
	}

	return head;
}

void Print(node * head){
	while(head){
		cout<<head->data<<" ";
		head = head->next;
	}
	return;
}

node * Merge(node * a, node * b){
	node* result = NULL;

    if (a == NULL)
        return(b);
    else if (b==NULL)
        return(a);

    if (a->data <= b->data)
    {
        result = a;
        result->next = Merge(a->next, b);
    }
    else
    {
        result = b;
        result->next = Merge(a, b->next);
    }

    return(result);
}


node * GetMiddle(node * head){
	node * ptr1 = head;
	node * ptr2 = head->next;

	while(ptr1 && ptr2 && ptr2->next){
		ptr1 = ptr1->next;
		ptr2 = ptr2->next->next;
	}
	return ptr1;
}

void MergeSort(node *& head){
	if( (head == NULL) || (head->next == NULL) ){
		return;
	}
	node * mid = GetMiddle(head);
	node * start1 = head;
	node * start2 = mid->next;
	mid->next = NULL;
	MergeSort(start1);
	MergeSort(start2);
	head = Merge(start1, start2);
}


int32_t main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 

	int n;
	cin>>n;

	node * head = createLL(n);
	MergeSort(head);
	Print(head);

	return 0;
}