#include<bits/stdc++.h>
#define int long long
using namespace std;

void Solve(string s, int i, int n, string temp, vector<string> &res){
	if(i == n){
		res.push_back(temp);
		res.push_back(", ");
		return;
	}
	if(s[i] > '0'){
		temp += (char)(96 + (int)(s[i]) - 48);
		Solve(s, i+1, n, temp, res);
		temp.pop_back();
	}
	if(i+1 < n and s[i] > '0' and s[i] < '3' and s[i+1] < '7'){
		int t1 = (int)(s[i])-48;
	    int t2 = (int)(s[i+1])-48;
		temp = temp + (char)(96 + t1*10+t2);
		Solve(s, i+2, n, temp, res);
		temp.pop_back();
	}
}


// void Solve2(string s, int n, string temp){
// 	if(n < 0){
// 		reverse(temp.begin(), temp.end());
// 		cout<<temp<<endl;
// 		return;
// 	}
// 	if(s[n] > '0'){
// 		temp += (char)(96 + (int)(s[n]) - 48);
// 		Solve2(s, n-1, temp);
// 		temp.pop_back();
// 	}
// 	if(n > 0 and s[n-1] > '0' and s[n-1] < '3' and s[n] < '7'){
// 		int t1 = (int)(s[n-1])-48;
// 	    int t2 = (int)(s[n])-48;
// 		temp = temp + (char)(96 + t1*10+t2);
// 		Solve2(s, n-2, temp);
// 		temp.pop_back();
// 	}
// }



int32_t main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 

	int n;
	cin>>n;

	string s = to_string(n);
	int len = s.length();
	string temp = "";
	vector<string> res;
	if(s[0] != 0){
		Solve(s, 0, len, temp, res);
		res.pop_back();
	}
	cout<<"[";
	for(auto x : res){
		cout<<x;
	}
	cout<<"]";
	return 0;
}