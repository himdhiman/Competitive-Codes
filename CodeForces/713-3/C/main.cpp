#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];
string s;

// int solve(string temp, int i, int j, int a, int b){
// 	if(i > j and a == '0' and b == '0'){
// 		return 1;
// 	}else{
// 		return -1;
// 	}
// 	if(i == j){
// 		if(a == 0 and b == 0 and temp[i] != '?'){
// 			return 1;
// 		}else if(b == 1 and a == 0 and temp[i] == '?'){
// 			temp[i] = '1';
// 			return 1;
// 		}else if(a == 1 and b == 0 and temp[i] == '?'){
// 			temp[i] = '0';
// 			return 1;
// 		}else {
// 			return -1;
// 		}
// 	}

// 	if(temp[i] == '?' and temp[j] == '0'){
// 		temp[i] = '0';
// 		solve(temp, i+1, j-1, a, b-1);
// 		temp[i] = '?';
// 	}
// 	if(temp[i] == '0' and temp[j] == '?'){
// 		temp[j] = '0';
// 		return solve(temp, i+1, j-1, a, b-1);
// 		temp[j] = '?';
// 	}
// 	if(temp[i] == '?' and temp[j] == '1'){
// 		temp[i] = '1';
// 		return solve(temp, i+1, j-1, a-1, b);
// 	}
// 	if(temp[i] == '1' and temp[j] == '?'){
// 		s[j] = '1';
// 		return solve(temp, i+1, j-1, a-1, b);
// 	}

// }
vector<string> ans;

void solve(string s, int start, int end, int a, int b){
	if(start > end){
		if(a == 0 and b == 0){
			ans.push_back(s);
			return;
		}
		return;
	}
	if(start == end){
		if(a == 1 and b == 0 and (s[start] == '?' or s[start] == '0')){
			s[start] = '0';
			ans.push_back(s);
			return;
		}else if(a == 0 and b == 1 and (s[start] == '?' or s[start] == '1')){
			s[start] = '1';
			ans.push_back(s);
			return;
		}else{
			// ans.push_back(s);
			return;
		}
	}
	if(s[start] != '?' and s[end] != '?'){
		if(s[start] != s[end]){
			return;
		}
		if(s[start] == '0'){
			if(a >= 2){
				s[end] = '0';
				// cout<<s<<" ";
				solve(s, start+1, end-1, a-2, b);
			}else{
				return;
			}
		}else{
			if(b >= 2){
				s[end] = '1';
				solve(s, start+1, end-1, a, b-2);
			}else{
				return;
			}
		}
	}
	if(s[start] == '?' or s[end] == '?'){
		if(s[start] == '?' and s[end] == '?'){
			if(a >= 2 and b >= 2){
				s[start] = '1';
				s[end] = '1';
				// cout<<s<<" ";
				solve(s, start+1, end-1, a, b-2);

				s[start] = '0';
				s[end] = '0';
				solve(s, start+1, end-1, a-2, b);

			}else if(a >= 2){
				s[start] = '0';
				s[end] = '0';
				solve(s, start+1, end-1, a-2, b);
			}else if(b >= 2){
				s[start] = '1';
				s[end] = '1';
				solve(s, start+1, end-1, a, b-2);
			}else{
				return;
			}
		}else if(s[start] == '?'){
			if(s[end] == '0'){
				if(a >= 2){
					s[start] = '0';
					s[end] = '0';
					// cout<<s<<" ";
					solve(s, start+1, end-1, a-2, b);
				}else{
					return;
				}
			}else{
				if(b >= 2){
					s[start] = '1';
					s[end] = '1';
					solve(s, start+1, end-1, a, b-2);
				}else{
					return;
				}
			}
		}else{
			if(s[start] == '0'){
				if(a >= 2){
					s[start] = '0';
					s[end] = '0';
					solve(s, start+1, end-1, a-2, b);
				}else{
					return;
				}
			}else{
				if(b >= 2){
					s[start] = '1';
					s[end] = '1';
					solve(s, start+1, end-1, a, b-2);
				}else{
					return;
				}
			}
		}
	}
	return;
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int t;
	cin>>t;
	while(t--){
		ans.clear();
		int a, b;
		cin>>a>>b;
		string s;
		cin>>s;
		int empty = 0;
		for(int i = 0; i < n; i++){
			if(s[i] == '?'){
				empty++;
			}
		}
		int start = 0, end = s.length()-1;
		while(start < end){
			if(s[start] != s[end]){
				if(s[start] == '0'){
					a -= 2;
				}else{
					b -= 2;
				}
				start++;
				end--;
			}else if(s[start] == '?' or s[end] == '?'){
				if(s[start] == '?' and s[end] == '?'){
					start++;
					end--;
					empty += 2;
				}else if(s[start] == '?'){
					if(s[end] == '0'){

					}
				}else if(s[end] == '?'){

				}
			}
		} 










		// // string temp = s;
		// solve(s, 0, s.length()-1, a, b);
		// // for(auto x : ans){
		// // 	cout<<x<<" ";
		// // }
		// if(ans.size() > 0){
		// 	cout<<ans[0]<<endl;
		// }else{
		// 	cout<<-1<<endl;
		// }
		// cout<<ans[0]<<endl;
		// cout<<s;
		// cout<<endl;
	}


	return 0;
}