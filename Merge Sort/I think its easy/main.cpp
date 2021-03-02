#include<bits/stdc++.h>
using namespace std;

bool comp(string a, string b){
	return a.length() < b.length();
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	cin>>t;
	string s;
	getline(cin, s);
	while(t--){
		multimap<int, string> m;
		getline(cin, s);
		string temp = "";
		for(int i = 0; i < s.length(); i++){
			if(s[i] == ' '){
				m.insert({temp.length(), temp});
				temp = "";
			}else{
				temp += s[i];
			}
		}
		m.insert({temp.length(), temp});
		for(auto x : m){
			cout<<" "<<x.second;
		}
		cout<<endl;
	}

}