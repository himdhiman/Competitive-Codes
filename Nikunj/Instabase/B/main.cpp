#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

bool isChar(char s){
	if(s >= 'A' and s <= 'Z'){
		return true;
	}
	return false;
}

bool isNum(char s){
	if(s >= '0' and s <= '9'){
		return true;
	}
	return false;
}

bool isLastValid(char s){
	if((s >= '0' and s <= '9') or(s >= 'A' and s <= 'Z') or (s >= 'a' and s <= 'z')){
		return true;
	}
	return false;
}


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	string s;
	getline(cin, s);
	vector<string> v;

	int start = 0, end = 0;
	while(end < s.length()){
		if(s[end] == ' '){
			v.push_back(s.substr(start, end-start));
			start = end+1;
		}
		end++;
	}
	v.push_back(s.substr(start, end-start));
	string ID = "", domain = "";
	for(auto x : v){
		string var = "";
		if(!isLastValid(x[x.length()-1])){
			var = x.substr(0, x.length()-1);
		}else{
			var = x;
		}
		if(var.substr(0, 4) == "www." and var.substr(var.length()-4, 4) == ".com"){
			domain = var;
		}else{
			if(var.length() == 10){
				bool flag = true;
				for(int i = 0; i < 5; i++){
					if(isChar(var[i])){
						flag = flag and true;
					}
				}
				for(int i = 5; i < 9; i++){
					if(isNum(var[i])){
						flag = flag and true;
					}
				}
				if(isChar(var[9])){
					flag = flag and true;
				}
				if(flag){
					ID = var;
				}
			}
		}
	}

	cout<<ID<<" "<<domain<<endl;	


	return 0;
}