#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

// vector<int> solve(string str){
// 	stack<pair<char, int> > s;
// 	vector<int> res;
// 	for(int i = 0; i < str.length(); i++){
// 		if(s.empty()){
// 			res.push_back(0);
// 		}else{
// 			auto curr = s.top();
// 			while(!s.empty() and curr.first == str[i]){
// 				s.pop();
// 				if(!s.empty()){
// 					curr = s.top();
// 				}else{
// 					break;
// 				}
// 			}
// 			if(s.empty()){
// 				res.push_back(0);
// 			}else{
// 				res.push_back(curr.second);
// 			}
// 		}
// 		s.push({str[i], i});
// 	}
// 	return res;
// }



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	cin>>t;
	while(t--){
		int a, b, p;
		cin>>a>>b>>p;
		string s;
		cin>>s;
		int pos = 1;
		char ch = '#';
		int n = s.length();
		for(int i = n-2; i >= 0; i--){
			if(s[i] != ch){
				if(s[i] == 'A' and p >= a){
					p -= a;
				}else if(s[i] == 'B' and p >= b){
					p -= b;
				}else{
					pos = i+2;
					break;
				}
			}
			ch = s[i];
		}
		cout<<pos<<endl;
		// vector<int> res = solve(s);
		// for(int i = 0; i < res.size(); i++){
		// 	if(res[i] != 0){
		// 		res[i]--;
		// 	}
		// }
		// for(auto x : res){
		// 	cout<<x<<" ";
		// }
		// int n = s.length();
		// while(true){
		// 	int curr = n-1;
		// 	int reachable = res[curr];
		// 	if(s[curr] == 'B'){
		// 		if((curr-reachable)*b <= p){
		// 			reachable = res[reachable];
		// 			p -= (curr-reachable)*b;
		// 		}
		// 	}else{
		// 		if((curr-reachable)*a <= p){
		// 			reachable = res[reachable];
		// 			p -= (curr-reachable)*b;
		// 		}
		// 	}
		// }


		// cout<<endl;
	}

	


	return 0;
}