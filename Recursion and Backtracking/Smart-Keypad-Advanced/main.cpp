#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<string> table = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
vector<string> input = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };

void Solve(string s, int i, int n, string temp){
	if(i == n){
		for(auto x : input){
			if(x.find(temp) != string::npos){
				cout<<x<<endl;
			}
		}
		return;
	}
	int ind = ((int)s[i]-48);
	string curr = table[ind];
	for(int k = 0; k < curr.length(); k++){
		temp += curr[k];
		Solve(s, i+1, n, temp);
		temp.pop_back();
	}
	return;
}



int32_t main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 

	int val; 
	string s;
	cin>>val;
	s = to_string(val);
	int n = s.length();
	string temp = "";
	Solve(s, 0, n, temp);
	return 0;
}