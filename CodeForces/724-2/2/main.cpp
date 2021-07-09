#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

vector<string> v;	


void solve(){
	string curr = "a";
	v.push_back(curr);
	while (curr != "zz") {
		int element = curr[curr.length() - 1];
		if (element < 122) {
			element++;
			curr[curr.length() - 1] = (char)element;
		}
		else {
			if (curr.length() == 1)
				curr = "aa";
			else {
				int start = curr[0];
				start ++;
				curr[0] = (char)start;
				curr[1] = 'a';
			}
		}
		v.push_back(curr);
	}
	v.push_back("zz");
	curr = "aaa";
	v.push_back(curr);
	while (curr != "zzz") {
		int element = curr[2];
		if (element < 122) {
			element++;
			curr[2] = (char)element;
		}
		else {
			int element2 = curr[1];
			if (element2 < 122) {
				element2++;
				curr[1] = (char)element2;
				curr[2] = 'a';
			}
			else {
				int element3 = curr[0];
				element3++;
				curr[0] = (char)element3;
				curr[1] = curr[2] = 'a';
			}
		}
		v.push_back(curr);
	}
	v.push_back(curr);
}


int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	solve();	
	int t;
	cin>>t;
	while(t--){
		int n;
		string str;
		cin>>n;
		cin>>str;
		unordered_map<string, bool> m;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				string curr = str.substr(i, j - i + 1);
				m[curr] = true;
			}
		}
		for (string s : v) {
			if (!m.count(s)) {
				cout << s << endl;
				break;
			}
		}
	}

	


	return 0;
}