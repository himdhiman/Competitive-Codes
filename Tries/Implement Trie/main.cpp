#include<bits/stdc++.h>
using namespace std;

class node{

public:
	char data;
	unordered_map<char, node *> children;
	bool isTerminal;

	node(char data){
		this->data = data;
		isTerminal = false;
	}
};


class Trie{

public:

	node * head;
	int cnt;

	Trie(){
		head = new node('\0');
		cnt = 0;
	}

	// INSERT
	void insert(string word){
		node * temp = head;
		for(int i = 0; i < word.length(); i++){
			if(temp->children.find(word[i]) != temp->children.end()){
				temp = temp->children[word[i]];
			}else{
				node * val = new node(word[i]);
				temp->children[word[i]] = val;
				temp = temp->children[word[i]];
			}
		}
		temp->isTerminal = true;
		cnt++;
	}

	// SEARCH

	bool search(string word){
		node * temp = head;
		for(int i = 0; i < word.length(); i++){
			if(temp->children.find(word[i]) == temp->children.end()){
				return false;
			}else{
				temp = temp->children[word[i]];
			}
		}
		return temp->isTerminal;
	}

	// STARTSWITH

	bool StartsWith(string word){
		node * temp = head;
		for(int i = 0; i < word.length(); i++){
			if(temp->children.find(word[i]) == temp->children.end()){
				return false;
			}else{
				temp = temp->children[word[i]];
			}
		}
		return true;
	}
};

int main(){
	Trie t;
	t.insert("apple");
	t.insert("pineapple");
	t.insert("water");
	cout<<t.search("water")<<endl;
	cout<<t.StartsWith("apu")<<endl;

}